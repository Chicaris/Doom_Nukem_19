/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:24:25 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 10:29:24 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		check_intersection(float res[2], t_wall wall)
{
	float	dir1[2];
	float	dir2[2];

	dir1[0] = res[0] - (float)wall.start[0];
	dir1[1] = res[1] - (float)wall.start[1];
	dir2[0] = res[0] - (float)wall.end[0];
	dir2[1] = res[1] - (float)wall.end[1];
	if (scalar_product_2(dir1, dir2) < 0)
		return (true);
	return (false);
}

t_bool		check_direction(float res[2], t_camera camera)
{
	float	dir1[2];
	float	dir2[2];

	dir1[0] = camera.origin[0] - res[0];
	dir1[1] = camera.origin[1] - res[1];
	dir2[0] = camera.lookat[0] - camera.origin[0];
	dir2[1] = camera.lookat[1] - camera.origin[1];
	if (scalar_product_2(dir1, dir2) < 0)
		return (true);
	return (false);
}

t_bool		is_intersection_2(t_wall wall, t_camera camera,
		float dir[3], float res[2])
{
	float		line[2][2];

	line[0][0] = wall.start[0];
	line[0][1] = wall.start[1];
	line[1][0] = wall.end[0];
	line[1][1] = wall.end[1];
	if (line_intersection(res, line, camera.origin, dir) == true)
		if (check_direction(res, camera) == true)
			return (true);
	return (false);
}

t_bool		is_intersection(t_wall wall, t_camera camera,
		float dir[3], float res[2])
{
	float		line[2][2];

	line[0][0] = wall.start[0];
	line[0][1] = wall.start[1];
	line[1][0] = wall.end[0];
	line[1][1] = wall.end[1];
	if (line_intersection(res, line, camera.origin, dir) == true)
		if (check_intersection(res, wall) == true)
			if (check_direction(res, camera) == true)
				return (true);
	return (false);
}

int			get_sector(t_core *core)
{
	unsigned int		i;

	i = 0;
	if (core->sector_in != -1)
		if (is_inside(core, core->sector_in) == true)
			return (core->sector_in);
	while (i < core->level.num_sectors)
	{
		if (is_inside(core, i) == true)
			return (i);
		i++;
	}
	return (-1);
}
