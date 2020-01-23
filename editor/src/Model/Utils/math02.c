/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:00 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:01:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/editor.h"

t_bool			is_intersection(t_wall *wall, float dir[2], float position[2])
{
	float		line[2][2];
	float		res[2];

	line[0][0] = wall->start[0];
	line[0][1] = wall->start[1];
	line[1][0] = wall->end[0];
	line[1][1] = wall->end[1];
	if (line_intersection(res, line, position, dir) == true)
	{
		if (check_intersection(res, wall) == true)
			if (check_direction(res, dir, position) == true)
				return (true);
	}
	return (false);
}

t_bool			is_in_sector(t_core *core, t_sector *sector, float point[2])
{
	int				i;
	int				counter;
	float			ray_dir[2];
	t_wall_lst		*current;
	t_wall			*wall;

	i = 0;
	ray_dir[0] = 1.0;
	ray_dir[1] = 1.0;
	current = get_wall_list(core, sector->start_wall);
	counter = 0;
	while (i < (int)sector->num_walls && current != NULL)
	{
		wall = current->wall;
		if (is_intersection(wall, ray_dir, point) == true)
			counter++;
		i++;
		current = current->next;
	}
	if (counter % 2 == 1)
		return (true);
	return (false);
}

int				get_closest_sector(t_core *core,
		t_sector_lst *sector_list, float x, float y)
{
	int			res;
	int			i;
	float		point[2];

	i = 0;
	res = -1;
	point[0] = x;
	point[1] = y;
	while (sector_list != NULL)
	{
		if (is_in_sector(core, sector_list->sector, point) == true)
			return (i);
		i++;
		sector_list = sector_list->next;
	}
	return (res);
}

void			init_point(float point[2], float x, float y)
{
	point[0] = x;
	point[1] = y;
}
