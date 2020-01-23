/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:31:45 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 10:48:14 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

static t_bool		ray_tst(float cl_inter[2][3], t_wall *wall,
		t_sector *sector, float inter[3])
{
	if (clip_wall(cl_inter[1], wall, sector) == true
			&& get_distance_vect(cl_inter[1], inter) > 0.01)
		return (true);
	return (false);
}

static void			ray_cpy(float lb[2], t_wall *wall[2], float cl_inter[2][3])
{
	lb[1] = lb[0];
	wall[0] = wall[1];
	vector_cpy(cl_inter[0], cl_inter[1]);
}

static void			ray_tmp(float cl_inter[2][3], float inter[3],
		float lb[2], float ray[3])
{
	vector_init(cl_inter[1],
			inter[0] + lb[0] * ray[0],
			inter[1] + lb[0] * ray[1],
			inter[2] + lb[0] * ray[2]);
}

static void			ray_init(unsigned int *i, float lb[2])
{
	*i = 0;
	lb[1] = -1;
}

t_wall				*ray_sector(t_core *core, int s_idx,
		float inter[3], float ray[3])
{
	unsigned int	i;
	t_wall			*wall[2];
	t_sector		sector;
	float			cl_inter[2][3];
	float			lb[2];

	ray_init(&i, lb);
	wall[0] = NULL;
	sector = core->level.sectors[s_idx];
	while (i < sector.num_walls)
	{
		wall[1] = &core->level.walls[sector.start_wall + i];
		if (get_lambda(&lb[0], inter, ray, wall[1]) == true)
		{
			ray_tmp(cl_inter, inter, lb, ray);
			if ((lb[0] < lb[1]) || (lb[1] < 0))
			{
				if (ray_tst(cl_inter, wall[1], &sector, inter) == true)
					ray_cpy(lb, wall, cl_inter);
			}
		}
		i++;
	}
	vector_cpy(inter, cl_inter[0]);
	return (wall[0]);
}
