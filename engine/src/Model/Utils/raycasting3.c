/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:36:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 16:47:39 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

static uint32_t		world_null(float ray_dir[3], float texture_offset[3],
		t_sector *sector, t_core *core)
{
	uint32_t	rgb;

	rgb = AMASK;
	if (ray_dir[2] > 0)
		rgb = get_sky_rgb(ray_dir, texture_offset, sector, core);
	else
	{
		if (get_z_intersection(texture_offset, ray_dir, sector->floor_height,
					core->camera.origin) == true)
			rgb = get_pixel(core->level.textures[sector->floor_texture],
					texture_offset[0], texture_offset[1]);
	}
	return (rgb);
}

static t_bool		world_tst(float i[3], t_core *core, t_wall *w)
{
	if ((i[2] < core->level.sectors[w->next_sector].floor_height)
			|| (i[2] > core->level.sectors[w->next_sector].ceiling_height))
		return (true);
	return (false);
}

static uint32_t		world_fc(float i[3], t_core *core, t_wall *w, float off[3])
{
	uint32_t	rgb;

	rgb = AMASK;
	if (i[2] < core->level.sectors[w->next_sector].floor_height)
		rgb = get_rgb(core, off, w, core->level.textures[w->b_texture]);
	else if (i[2] > core->level.sectors[w->next_sector].ceiling_height)
		rgb = get_rgb(core, off, w, core->level.textures[w->t_texture]);
	return (rgb);
}

static uint32_t		norme_world(t_core *core, t_wall *w, float vect[2][3],
		t_sector *sector)
{
	uint32_t	rgb;

	rgb = AMASK;
	if (w->next_sector != -1)
	{
		if (world_tst(vect[1], core, w) == true)
			rgb = world_fc(vect[1], core, w, vect[0]);
		else
		{
			if (w->m_texture == 0)
			{
				if ((rgb = get_door_rgb(core, w, vect[1], sector)) == RED)
					rgb = get_world_rgb(core, w->next_sector, vect[2], vect[1]);
			}
			else
				rgb = get_world_rgb(core, w->next_sector, vect[2], vect[1]);
		}
	}
	else
		rgb = get_rgb(core, vect[0], w, core->level.textures[w->m_texture]);
	return (rgb);
}

uint32_t			get_world_rgb(t_core *core, int cur_sector,
		float ray_dir[3], float i[3])
{
	t_wall		*w;
	float		off[3];
	float		vect[3][3];
	t_sector	*sector;
	uint32_t	rgb;

	rgb = AMASK;
	sector = &core->level.sectors[cur_sector];
	w = ray_sector(core, cur_sector, i, ray_dir);
	if (w != NULL)
	{
		get_texture_offset(w, i, off, sector);
		norminette_vect(vect, off, i, ray_dir);
		rgb = norme_world(core, w, vect, sector);
	}
	else
		rgb = world_null(ray_dir, off, sector, core);
	return (rgb);
}
