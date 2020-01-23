/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:41:41 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/04 11:16:49 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_monster			*init_monster(t_core *core, float x, float y)
{
	t_monster	*monster;
	t_sector	*sector;

	if (!(monster = (t_monster *)malloc(sizeof(t_monster))))
		return (NULL);
	monster->texture = 8;
	printf("monster_texture %i\n", monster->texture);
	monster->origin[0] = x;
	monster->origin[1] = y;
	monster->sector_idx = get_sector_idx(core, monster);
	sector = get_sector(core, monster->sector_idx);
	monster->origin[2] = sector->floor_height;
	return (monster);
}

t_monster			*monster_cpy(t_monster *src)
{
	t_monster *dest;

	if (!(dest = (t_monster *)malloc(sizeof(t_monster))))
		return (NULL);
	dest->texture = src->texture;
	dest->origin[0] = src->origin[0];
	dest->origin[1] = src->origin[1];
	dest->origin[2] = src->origin[2];
	dest->sector_idx = src->sector_idx;
	return (dest);
}

t_bool				add_monster(t_core *core, t_monster *monster)
{
	t_monster_lst	*curr;

	curr = core->monster_list;
	if (core->monster_list == NULL)
	{
		if (!(core->monster_list =
					(t_monster_lst *)malloc(sizeof(t_monster_lst))))
			error_msg("Didn't malloc a monster_lst");
		core->monster_list->monster = monster_cpy(monster);
		core->monster_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_monster_lst *)malloc(sizeof(t_monster_lst))))
			error_msg("Didn't malloc a monster_lst");
		curr->next->monster = monster_cpy(monster);
		curr->next->next = NULL;
	}
	return (true);
}

void				undo_last_monster(t_core *core)
{
	t_monster_lst		*prev;
	t_monster_lst		*curr;

	prev = core->monster_list;
	if (prev == NULL)
		return ;
	if (prev->next == NULL)
	{
		free(prev);
		core->monster_list = NULL;
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
