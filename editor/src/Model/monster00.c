/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:41:37 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/04 11:16:10 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				monster_texture_change(t_core *core, int step)
{
	int					i;
	t_monster_lst		*current;

	i = 0;
	current = core->monster_list;
	if (core->select->monster >= 0)
	{
		while (i < core->select->monster && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->monster->texture + step > 8 &&
			current->monster->texture + step <= 9)
			current->monster->texture += step;
		else
			current->monster->texture = 8;
	}
}

t_monster			*get_monster(t_core *core, int pos)
{
	int					i;
	t_monster_lst		*current;

	i = 0;
	current = core->monster_list;
	if (current == NULL)
		return (NULL);
	while (i < pos && current != NULL)
	{
		i++;
		current = current->next;
	}
	return (current->monster);
}

int					get_nbr_monster(t_core *core)
{
	int					i;
	t_monster_lst		*current;

	i = 0;
	current = core->monster_list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_bool				is_monster_ok(t_core *core, t_monster *monster)
{
	float			point[2];
	t_sector_lst	*curr;

	point[0] = monster->origin[0];
	point[1] = monster->origin[1];
	curr = core->sector_list;
	while (curr != NULL)
	{
		if (is_in_sector(core, curr->sector, point) == true)
			return (true);
		curr = curr->next;
	}
	return (false);
}

int					get_sector_idx(t_core *core, t_monster *monster)
{
	int				i;
	float			point[2];
	t_sector_lst	*curr;

	i = 0;
	curr = core->sector_list;
	point[0] = monster->origin[0];
	point[1] = monster->origin[1];
	while (curr != NULL)
	{
		if (is_in_sector(core, curr->sector, point) == true)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}
