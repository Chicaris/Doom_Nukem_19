/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:11:12 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 12:20:04 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

uint32_t		get_pixel_monster(t_core *core, t_monster *closest_monster,
		float intersection[3])
{
	uint32_t	rgb;
	float		offset[2];

	get_texture_offset_monster(closest_monster, intersection, offset);
	rgb = get_pixel(core->level.textures[closest_monster->texture],
			offset[0], offset[1]);
	return (rgb);
}

uint32_t		get_pixel_pickup(t_core *core, t_pickup *closest_pickup,
		float intersection[3])
{
	uint32_t	rgb;
	float		offset[2];

	gtop(closest_pickup, intersection, offset);
	rgb = get_pixel(core->level.textures[closest_pickup->texture],
			offset[0], offset[1]);
	return (rgb);
}

uint32_t		get_final_color(t_core *core, int cur_sector, float ray_dir[3])
{
	uint32_t	rgb;
	t_monster	*closest_monster;
	float		i[3][3];
	t_pickup	*pickup;

	vector_cpy(i[0], core->camera.origin);
	rgb = get_world_rgb(core, cur_sector, ray_dir, i[0]);
	closest_monster = ray_monster(core, i[1], ray_dir);
	pickup = ray_pickup(core, i[2], ray_dir);
	if (closest_monster != NULL && pickup != NULL)
	{
		if (get_distance_vect(i[1], core->camera.origin) <
				get_distance_vect(i[2], core->camera.origin))
			rgb = get_pixel_monster(core, closest_monster, i[1]);
		else
			rgb = get_pixel_pickup(core, pickup, i[2]);
	}
	else if (closest_monster != NULL)
		rgb = get_pixel_monster(core, closest_monster, i[1]);
	else if (pickup != NULL)
		rgb = get_pixel_pickup(core, pickup, i[2]);
	return (rgb);
}

void			init_raycast(float ray_dir[3], int x[2], t_core *core,
		float matrix[4][4])
{
	float	ray[3];

	vector_init(ray, x[1] - WIN_HEIGHT / 2,
			x[0] - WIN_WIDTH / 2, core->camera.focal);
	vector_transform(ray, matrix, ray);
	vector_diff(ray_dir, core->camera.origin, ray);
}

void			*raycast(void *args)
{
	t_core		*core;
	int			x[2];
	float		ray[3];
	float		matrix[4][4];

	core = ((t_raycast_args *)args)->core;
	camera_to_world(&core->camera, matrix);
	init_monster_list(core);
	x[0] = ((t_raycast_args *)args)->x_begin;
	while (x[0] < (((t_raycast_args *)args)->x_begin +
				((t_raycast_args *)args)->n_steps))
	{
		x[1] = 0;
		while (x[1] < WIN_HEIGHT)
		{
			init_raycast(ray, x, core, matrix);
			set_pixel(core->sdl.surface, x[0], WIN_HEIGHT - 1 - x[1],
					get_final_color(core, core->sector_in, ray));
			x[1]++;
		}
		x[0]++;
	}
	return (core);
}
