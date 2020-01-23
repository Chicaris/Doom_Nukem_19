/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:14:51 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:00:29 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

int				get_start_wall(t_core *core)
{
	int				start;
	t_sector_lst	*sector_last;

	if (core->sector_list == NULL)
		start = 0;
	else
	{
		sector_last = get_last_sector(core);
		start = sector_last->sector->start_wall +
			sector_last->sector->num_walls;
	}
	return (start);
}

t_sector		*get_sector(t_core *core, int pos)
{
	int				i;
	t_sector_lst	*current;

	i = 0;
	current = core->sector_list;
	while (i < pos && current != NULL)
	{
		i++;
		current = current->next;
	}
	return (current->sector);
}

void			is_new_sector(t_core *core)
{
	int			start;
	t_sector	sector;
	t_wall_lst	*wall_list;
	t_wall_lst	*last_wall;

	start = get_start_wall(core);
	wall_list = get_wall_list(core, start);
	if (wall_list != NULL)
	{
		last_wall = get_last_wall(core);
		if (is_point_equal(wall_list->wall->start,
					last_wall->wall->end) == true)
		{
			sector = (t_sector) {start, get_nbr_wall(wall_list, 0),
				0.0, 5.0, 2, 3};
			add_sector(core, &sector);
		}
	}
}

t_bool			is_wall_in_sector(t_core *core, int idx_wall)
{
	t_sector_lst		*last_sector;
	t_sector			*sector;

	last_sector = get_last_sector(core);
	if (last_sector != NULL)
	{
		sector = last_sector->sector;
		if (idx_wall >= (int)sector->start_wall && idx_wall <
				(int)(sector->start_wall + sector->num_walls))
			return (true);
	}
	return (false);
}

void			undo_last_sector(t_core *core)
{
	t_sector_lst		*prev;
	t_sector_lst		*curr;

	prev = core->sector_list;
	if (prev == NULL)
		return ;
	if (prev->next == NULL)
	{
		free(prev->sector);
		free(prev);
		core->sector_list = NULL;
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
		free(curr->sector);
		free(curr);
	}
}
