/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sector1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:53:43 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 13:53:44 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		is_inside(t_core *core, int idx_sector)
{
	int				counter;
	unsigned int	i;
	t_wall			wall;
	float			intersect[2];
	float			dir[3];

	counter = 0;
	i = 0;
	if (core->camera.origin[2] <
		(float)core->level.sectors[idx_sector].floor_height
	|| core->camera.origin[2] > core->level.sectors[idx_sector].ceiling_height)
		return (false);
	while (i < core->level.sectors[idx_sector].num_walls)
	{
		wall =
			core->level.walls[(core->level.sectors[idx_sector].start_wall + i)];
		vector_diff(dir, core->camera.origin, core->camera.lookat);
		if (is_intersection(wall, core->camera, dir, intersect) == true)
			counter++;
		i++;
	}
	if (counter % 2 != 0)
		return (true);
	return (false);
}
