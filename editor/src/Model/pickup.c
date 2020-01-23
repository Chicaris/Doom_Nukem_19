/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:12:37 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/04 13:44:08 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

int					get_sector_idx_pickup(t_core *core, t_pickup *pickup)
{
	int				i;
	float			point[2];
	t_sector_lst	*curr;

	i = 0;
	curr = core->sector_list;
	point[0] = pickup->center[0];
	point[1] = pickup->center[1];
	while (curr != NULL)
	{
		if (is_in_sector(core, curr->sector, point) == true)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

t_pickup			*init_pickup(t_core *core, float x, float y)
{
	t_pickup	*pickup;
	t_sector	*sector;

	if (!(pickup = (t_pickup *)malloc(sizeof(t_pickup))))
		return (NULL);
	pickup->texture = NUM_WALL_TEXTURES;
	pickup->item_id = 1;
	pickup->center[0] = x;
	pickup->center[1] = y;
	pickup->sector_idx = get_sector_idx_pickup(core, pickup);
	sector = get_sector(core, pickup->sector_idx);
	pickup->center[2] = sector->floor_height;
	return (pickup);
}

t_pickup			*pickup_cpy(t_pickup *src)
{
	t_pickup *dest;

	if (!(dest = (t_pickup *)malloc(sizeof(t_pickup))))
		return (NULL);
	dest->texture = src->texture;
	dest->item_id = src->item_id;
	dest->center[0] = src->center[0];
	dest->center[1] = src->center[1];
	dest->center[2] = src->center[2];
	dest->sector_idx = src->sector_idx;
	return (dest);
}

t_bool				add_pickup(t_core *core, t_pickup *pickup)
{
	t_pickup_lst	*curr;

	curr = core->pickup_list;
	if (core->pickup_list == NULL)
	{
		if (!(core->pickup_list =
					(t_pickup_lst *)malloc(sizeof(t_pickup_lst))))
			error_msg("Didn't malloc a pickup_lst");
		core->pickup_list->pickup = pickup_cpy(pickup);
		core->pickup_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_pickup_lst *)malloc(sizeof(t_pickup_lst))))
			error_msg("Didn't malloc a pickup_lst");
		curr->next->pickup = pickup_cpy(pickup);
		curr->next->next = NULL;
	}
	return (true);
}

void				undo_last_pickup(t_core *core)
{
	t_pickup_lst		*prev;
	t_pickup_lst		*curr;

	prev = core->pickup_list;
	if (prev == NULL)
		return ;
	if (prev->next == NULL)
	{
		free(prev);
		core->pickup_list = NULL;
	}
	else
	{
		curr = prev->next;
		while (curr->next != NULL)
		{
			prev = prev->next;
			curr = curr->next;
		}
		prev->next = NULL;
		free(curr);
	}
	paint(core);
}
