/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:55:21 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:55:22 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				pickup_id_change(t_core *core, int step)
{
	int					i;
	t_pickup_lst		*current;

	i = 0;
	current = core->pickup_list;
	if (core->select->pickup >= 0)
	{
		while (i < core->select->pickup && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->pickup->item_id + step < 8)
			current->pickup->item_id += step;
		else
			current->pickup->item_id = 0;
	}
}

void				pickup_texture_change(t_core *core, int step)
{
	int					i;
	t_pickup_lst		*current;

	i = 0;
	current = core->pickup_list;
	if (core->select->pickup >= 0)
	{
		while (i < core->select->pickup && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->pickup->texture + step < NUM_TEXTURES)
			current->pickup->texture += step;
		else
			current->pickup->texture = 0;
	}
}

t_pickup			*get_pickup(t_core *core, int pos)
{
	int					i;
	t_pickup_lst		*current;

	i = 0;
	current = core->pickup_list;
	if (current == NULL)
		return (NULL);
	while (i < pos && current != NULL)
	{
		i++;
		current = current->next;
	}
	return (current->pickup);
}

int					get_nbr_pickup(t_core *core)
{
	int					i;
	t_pickup_lst		*current;

	i = 0;
	current = core->pickup_list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_bool				is_pickup_ok(t_core *core, t_pickup *pickup)
{
	float			point[2];
	t_sector_lst	*curr;

	point[0] = pickup->center[0];
	point[1] = pickup->center[1];
	curr = core->sector_list;
	while (curr != NULL)
	{
		if (is_in_sector(core, curr->sector, point) == true)
			return (true);
		curr = curr->next;
	}
	return (false);
}
