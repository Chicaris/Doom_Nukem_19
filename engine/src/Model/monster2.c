/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:22:07 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/18 14:15:24 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_bool			add_monster(t_level_data *level_data, t_monster *monster)
{
	t_monster_lst	*curr;

	curr = level_data->monster_list;
	if (level_data->monster_list == NULL)
	{
		if (!(level_data->monster_list =
				(t_monster_lst *)malloc(sizeof(t_monster_lst))))
			return (false);
		level_data->monster_list->monster = monster_cpy(monster);
		level_data->monster_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_monster_lst *)malloc(sizeof(t_monster_lst))))
		{
			ft_putstr("Didn't malloc a monster_lst");
			return (false);
		}
		curr->next->monster = monster_cpy(monster);
		curr->next->next = NULL;
	}
	return (true);
}

int				get_monster_nbr(t_monster_lst *monster_list)
{
	int				i;
	t_monster_lst	*curr;

	i = 0;
	curr = monster_list;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void			delete_monster(t_core *core, int idx)
{
	int				i;
	t_monster_lst	*curr;
	t_monster_lst	*prev;

	i = 0;
	curr = core->level.monster_list;
	if (curr != NULL && i == idx)
	{
		core->level.monster_list = curr->next;
		free(curr->monster);
		free(curr);
		return ;
	}
	while (curr != NULL && i != idx)
	{
		prev = curr;
		i++;
		curr = curr->next;
	}
	if (curr == NULL)
		return ;
	prev->next = curr->next;
	free(curr->monster);
	free(curr);
}

void			delete_monster_2(t_core *core, t_monster *monster)
{
	t_monster_lst	*curr;
	t_monster_lst	*prev;

	curr = core->level.monster_list;
	if (curr != NULL && curr->monster == monster)
	{
		core->level.monster_list = curr->next;
		free(curr->monster);
		free(curr);
		return ;
	}
	while (curr != NULL && curr->monster != monster)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return ;
	prev->next = curr->next;
	free(curr->monster);
	free(curr);
}
