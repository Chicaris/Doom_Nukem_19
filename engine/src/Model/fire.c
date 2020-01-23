/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:16:36 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:14:59 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void			init_ray_dir(t_core *core, float ray_dir[3])
{
	float		ray[3];
	float		matrix[4][4];

	vector_init(ray, 0.0, 0.0, core->camera.focal);
	camera_to_world(&core->camera, matrix);
	vector_transform(ray, matrix, ray);
	vector_diff(ray_dir, core->camera.origin, ray);
	vector_normalize(ray_dir);
}

void			get_closest_wall2(t_core *core,
		t_wall *closest_wall, float offset[3])
{
	t_flag	flag;

	flag = (t_flag) {61, {offset[0] -
	core->level.textures[61]->w / 2, offset[1] -
	core->level.textures[61]->h / 2, 0.0},
	core->level.textures[61]->w, core->level.textures[61]->h};
	closest_wall->flag = flag_cpy(&flag);
}

static void		get_closest_wall1(t_core *core, float i[3], t_wall *w,
	float ray_dir[3])
{
	int		curr_sector;
	float	offset[3];

	curr_sector = core->sector_in;
	if (!((i[2] < core->level.sectors[w->next_sector].floor_height)
			|| (i[2] > core->level.sectors[w->next_sector].ceiling_height)))
		w = get_closest_wall(core, w->next_sector,
					i, ray_dir);
	else
	{
		get_texture_offset(w, i, offset,
				&core->level.sectors[curr_sector]);
		get_closest_wall2(core, w,
					offset);
	}
}

t_wall			*get_closest_wall(t_core *core, int curr_sector,
		float i[3], float ray_dir[3])
{
	t_wall		*w;
	t_flag		flag;
	float		offset[3];

	w = ray_sector(core, curr_sector, i, ray_dir);
	if (w != NULL)
	{
		if (w->next_sector != -1)
			get_closest_wall1(core, i, w, ray_dir);
		else
		{
			get_texture_offset(w, i, offset, &core->level.sectors[curr_sector]);
			flag = (t_flag) {61, {offset[0] - core->level.textures[61]->w / 2,
offset[1] - core->level.textures[61]->h / 2, 0.0},
core->level.textures[61]->w, core->level.textures[61]->h};
			w->flag = flag_cpy(&flag);
		}
	}
	return (w);
}

void			fire(t_core *core)
{
	float		intersection[3];
	float		ray_dir[3];
	t_wall		*closest_wall;
	t_monster	*closest_monster;

	if (core->player.gun[core->player.active_wp].w_magazine - 1 >= 0)
	{
		core->player.gun[core->player.active_wp].w_status = 1;
		if (Mix_PlayChannel(1, core->level.samples[2 +
					core->player.active_wp], 0) == -1)
			ft_putstr("sound not working\n");
		init_ray_dir(core, ray_dir);
		vector_cpy(intersection, core->camera.origin);
		closest_wall = get_closest_wall(core, core->sector_in,
				intersection, ray_dir);
		closest_monster = ray_monster(core, intersection, ray_dir);
		if (closest_monster != NULL)
		{
			delete_monster_2(core, closest_monster);
			if (core->level.monster_list == NULL)
				core->game_status = you_win;
		}
	}
}
