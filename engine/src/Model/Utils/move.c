/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:21:38 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 11:11:35 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		check_objet(t_core *core, t_pickup *item, float pos[3],
		float intersection[3])
{
	float		v1[3];
	float		v2[3];
	t_pickup	*pickup;

	pickup = item;
	vector_diff(v1, intersection, core->camera.origin);
	vector_diff(v2, intersection, pos);
	if (scalar_product_3(v1, v2) > 0)
		return (true);
	return (false);
}

t_bool		check_list_objet(t_core *core, float pos[3])
{
	float		dir[3];
	float		intersection[3];
	t_pickup	*pickup;

	vector_diff(dir, core->camera.origin, pos);
	pickup = ray_pickup(core, intersection, dir);
	if (pickup != NULL)
	{
		if (check_objet(core, pickup, pos, intersection) == false)
			return (false);
	}
	return (true);
}

t_bool		check_door_wall(t_core *core, t_wall *wall, float pos[3],
		float intersection[3])
{
	float	v1[3];
	float	v2[3];
	t_wall	*tmp;

	tmp = wall;
	vector_diff(v1, intersection, core->camera.origin);
	vector_diff(v2, intersection, pos);
	if (scalar_product_3(v1, v2) > 0)
		return (true);
	return (false);
}

t_bool		check_door(t_core *core, float pos[3])
{
	float		dir[3];
	float		intersection[3];
	t_wall		*wall;
	t_sector	*sector;

	vector_diff(dir, core->camera.origin, pos);
	vector_cpy(intersection, core->camera.origin);
	wall = ray_sector(core, core->sector_in, intersection, dir);
	if (wall != NULL)
	{
		if (wall->next_sector != -1)
		{
			sector = &core->level.sectors[wall->next_sector];
			if (check_door_wall(core, wall, pos, intersection) == false)
			{
				if (intersection[2] < sector->floor_height
						|| intersection[2] > sector->ceiling_height)
					return (false);
				if (wall->m_texture == 0 && core->step_door > 0.0)
					return (false);
			}
		}
	}
	return (true);
}
