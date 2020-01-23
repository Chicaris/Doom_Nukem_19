/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:02 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:29:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/editor.h"

void			get_closest_wall_2(float dist[2], int *res, int *i)
{
	dist[1] = dist[0];
	*res = *i;
}

int				get_closest_wall(t_core *core,
		t_wall_lst *wall_list, float x, float y)
{
	int				i;
	int				res;
	float			dist[2];
	t_sector		*sector;
	float			point[2];

	i = 0;
	dist[1] = -1.0;
	res = -1;
	sector = get_sector(core, core->select->sector);
	init_point(point, x, y);
	while (wall_list != NULL)
	{
		dist[0] = dist_point_droite(point, wall_list->wall);
		if ((dist[1] < 0.0 || dist[0] < dist[1]) && (dist[0] < 0.5
					&& clip_wall(point, wall_list->wall) == true))
		{
			if (i >= (int)sector->start_wall && i <
					(int)(sector->start_wall + sector->num_walls))
				get_closest_wall_2(dist, &res, &i);
		}
		i++;
		wall_list = wall_list->next;
	}
	return (res);
}

float			get_distance(float origin[3], float inter[2])
{
	float		a;
	float		b;

	a = inter[0] - origin[0];
	b = inter[1] - origin[1];
	return (sqrtf(a * a + b * b));
}

int				get_closest_monster(t_monster_lst *monster_list,
		float x, float y)
{
	int			res;
	int			i;
	float		point[2];
	float		current_dist;
	float		closest_dist;

	i = 0;
	res = -1;
	closest_dist = -1.0;
	init_point(point, x, y);
	while (monster_list != NULL)
	{
		current_dist = get_distance(monster_list->monster->origin, point);
		if (closest_dist < 0.0 || current_dist < closest_dist)
		{
			if (current_dist < 0.5)
			{
				closest_dist = current_dist;
				res = i;
			}
		}
		i++;
		monster_list = monster_list->next;
	}
	return (res);
}

int				get_closest_pickup(t_pickup_lst *pickup_list, float x, float y)
{
	int			res;
	int			i;
	float		point[2];
	float		current_dist;
	float		closest_dist;

	i = 0;
	res = -1;
	closest_dist = -1.0;
	init_point(point, x, y);
	while (pickup_list != NULL)
	{
		current_dist = get_distance(pickup_list->pickup->center, point);
		if (closest_dist < 0.0 || current_dist < closest_dist)
		{
			if (current_dist < 0.5)
			{
				closest_dist = current_dist;
				res = i;
			}
		}
		i++;
		pickup_list = pickup_list->next;
	}
	return (res);
}
