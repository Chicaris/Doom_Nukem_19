/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:35 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:29:18 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_wall			*wall_cpy(t_wall *src)
{
	t_wall		*dest;

	if (!(dest = (t_wall *)malloc(sizeof(t_wall))))
		return (NULL);
	ft_memset(dest, 0, sizeof(t_wall));
	dest->start[0] = src->start[0];
	dest->start[1] = src->start[1];
	dest->end[0] = src->end[0];
	dest->end[1] = src->end[1];
	dest->next_sector = src->next_sector;
	dest->b_texture = src->b_texture;
	dest->m_texture = src->m_texture;
	dest->t_texture = src->t_texture;
	dest->flag = flag_cpy(src->flag);
	return (dest);
}

t_bool			add_wall(t_core *core, t_wall *wall)
{
	t_wall_lst		*curr;

	curr = core->wall_list;
	if (core->wall_list == NULL)
	{
		if (!(core->wall_list = (t_wall_lst *)malloc(sizeof(t_wall_lst))))
			error_msg("Didn't malloc a t_wall_lst\n");
		core->wall_list->wall = wall_cpy(wall);
		core->wall_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_wall_lst *)malloc(sizeof(t_wall_lst))))
			error_msg("Didn't malloc a t_wall_lst\n");
		curr->next->wall = wall_cpy(wall);
		curr->next->next = NULL;
	}
	return (true);
}

void			undo_check_first(t_core *core)
{
	free_wall(core->wall_list->wall);
	free(core->wall_list);
	core->wall_list = NULL;
}

void			check_sector_undo(t_core *core, int i)
{
	if (is_wall_in_sector(core, i) == true)
		undo_last_sector(core);
}

void			undo_last_wall(t_core *core)
{
	t_wall_lst			*prev;
	t_wall_lst			*curr;
	int					i;

	i = 1;
	reset_first_click(core);
	prev = core->wall_list;
	if (prev == NULL)
		return ;
	if (prev->next == NULL)
		undo_check_first(core);
	else
	{
		curr = prev->next;
		while (curr->next != NULL)
		{
			prev = prev->next;
			curr = curr->next;
			i++;
		}
		prev->next = NULL;
		free_wall(curr->wall);
		free(curr);
		check_sector_undo(core, i);
	}
}
