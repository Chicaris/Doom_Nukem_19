/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:52:01 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 09:46:49 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		is_good(t_core *core, int idx_sector, float intersection[3],
		float ray_dir[3])
{
	int				counter;
	unsigned int	i;
	t_wall			wall;

	counter = 0;
	i = 0;
	if (intersection[2] < (float)core->level.sectors[idx_sector].floor_height
	|| intersection[2] > (float)core->level.sectors[idx_sector].ceiling_height)
		return (false);
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

t_bool		is_inside_maze(t_core *core, float position[3])
{
	unsigned int		idx;

	idx = 0;
	while (idx < core->level.num_sectors)
	{
		if (check_mouvement(core, position, idx) == true)
			return (true);
		idx++;
	}
	return (false);
}

t_bool		check_mouvement(t_core *core, float position[3], int sector_idx)
{
	if (is_good(core, sector_idx, position, core->camera.lookat) == true)
		return (true);
	return (false);
}
