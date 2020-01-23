/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:40:26 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 10:11:40 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		get_z_intersection(float res[3], float ray[3],
		float z, float origin[3])
{
	if (float_equality(ray[2], 0.0) == false)
	{
		res[0] = fabsf((ray[0] / ray[2]) * (z - origin[2]) + origin[0]);
		res[1] = fabsf((ray[1] / ray[2]) * (z - origin[2]) + origin[1]);
		res[2] = fabsf(z);
		return (true);
	}
	return (false);
}

t_bool		check_direction_sector(float res[2], float ray_dir[3],
		float position[3])
{
	float	dir1[2];
	float	dir2[2];

	dir1[0] = position[0] - res[0];
	dir1[1] = position[1] - res[1];
	dir2[0] = ray_dir[0];
	dir2[1] = ray_dir[1];
	if (scalar_product_2(dir1, dir2) < 0)
		return (true);
	return (false);
}

t_bool		is_intersection_sector(t_wall wall, t_camera camera,
		float dir[3], float position[3])
{
	float		line[2][2];
	float		res[2];
	t_camera	tmp;

	tmp = camera;
	line[0][0] = wall.start[0];
	line[0][1] = wall.start[1];
	line[1][0] = wall.end[0];
	line[1][1] = wall.end[1];
	if (line_intersection(res, line, position, dir) == true)
		if (check_intersection(res, wall) == true)
			if (check_direction_sector(res, dir, position) == true)
				return (true);
	return (false);
}

t_bool		is_inside_sector(t_core *core, int idx_sector,
		float intersection[3], float ray_dir[3])
{
	int				counter;
	unsigned int	i;
	t_wall			wall;

	counter = 0;
	i = 0;
	while (i < core->level.sectors[idx_sector].num_walls)
	{
		wall =
			core->level.walls[(core->level.sectors[idx_sector].start_wall + i)];
		if (is_intersection_sector(wall, core->camera, ray_dir, intersection)
				== true)
			counter++;
		i++;
	}
	if (counter % 2 == 1)
		return (true);
	return (false);
}
