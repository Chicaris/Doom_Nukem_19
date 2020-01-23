/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:14:54 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 14:14:57 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_sector		*sector_cpy(t_sector *src)
{
	t_sector	*dest;

	if (!(dest = (t_sector *)malloc(sizeof(t_sector))))
		return (NULL);
	dest->start_wall = src->start_wall;
	dest->num_walls = src->num_walls;
	dest->floor_height = src->floor_height;
	dest->ceiling_height = src->ceiling_height;
	dest->floor_texture = src->floor_texture;
	dest->ceiling_texture = src->ceiling_texture;
	return (dest);
}

t_bool			add_sector(t_core *core, t_sector *sector)
{
	t_sector_lst		*curr;

	curr = core->sector_list;
	if (core->sector_list == NULL)
	{
		if (!(core->sector_list = (t_sector_lst *)malloc(sizeof(t_sector_lst))))
			error_msg("Didn't malloc a t_sector_lst\n");
		core->sector_list->sector = sector_cpy(sector);
		core->sector_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_sector_lst *)malloc(sizeof(t_sector_lst))))
			error_msg("Didn't malloc a t_sector_lst\n");
		curr->next->sector = sector_cpy(sector);
		curr->next->next = NULL;
	}
	return (true);
}

t_sector_lst	*get_last_sector(t_core *core)
{
	t_sector_lst	*current;

	current = core->sector_list;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
