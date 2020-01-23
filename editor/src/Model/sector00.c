/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:14:48 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:24:39 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void			ceil_texture_change(t_core *core, int step)
{
	int					i;
	t_sector_lst		*current;

	i = 0;
	current = core->sector_list;
	if (core->select->sector >= 0)
	{
		while (i < core->select->sector && current != NULL)
		{
			current = current->next;
			i++;
		}
		if (current->sector->ceiling_texture + step < NUM_WALL_TEXTURES)
			current->sector->ceiling_texture += step;
		else
			current->sector->ceiling_texture = 0;
	}
}

void			floor_texture_change(t_core *core, int step)
{
	int					i;
	t_sector_lst		*current;

	i = 0;
	current = core->sector_list;
	if (core->select->sector >= 0)
	{
		while (i < core->select->sector && current != NULL)
		{
			current = current->next;
			i++;
		}
		if (current->sector->floor_texture + step < NUM_WALL_TEXTURES)
			current->sector->floor_texture += step;
		if (current->sector->floor_texture == 62)
			current->sector->floor_texture = 0;
		if (current->sector->floor_texture + step == NUM_WALL_TEXTURES)
			current->sector->floor_texture = 62;
	}
}

void			ceil_change(t_core *core, float step)
{
	int					i;
	t_sector_lst		*current;

	i = 0;
	current = core->sector_list;
	if (core->select->sector >= 0)
	{
		while (i < core->select->sector && current != NULL)
		{
			current = current->next;
			i++;
		}
		if (current->sector->ceiling_height + step >= 0.0)
			if (current->sector->ceiling_height + step >
					current->sector->floor_height)
				current->sector->ceiling_height += step;
	}
}

void			floor_change(t_core *core, float step)
{
	int				i;
	t_sector_lst	*current;

	i = 0;
	current = core->sector_list;
	if (core->select->sector >= 0)
	{
		while (i < core->select->sector && current != NULL)
		{
			current = current->next;
			i++;
		}
		if (current->sector->floor_height + step >= 0.0)
			if (current->sector->floor_height + step <
					current->sector->ceiling_height)
				current->sector->floor_height += step;
	}
}

int				get_nbr_sector(t_sector_lst *sector_list, int start)
{
	int		nbr;

	nbr = start;
	while (sector_list != NULL)
	{
		nbr++;
		sector_list = sector_list->next;
	}
	return (nbr);
}
