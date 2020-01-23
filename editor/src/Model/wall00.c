/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:33 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/25 10:04:17 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_wall			*get_wall(t_core *core, int pos)
{
	int				i;
	t_wall_lst		*current;

	i = 0;
	current = core->wall_list;
	while (i < pos && current != NULL)
	{
		i++;
		current = current->next;
	}
	return (current->wall);
}

void			t_texture_change(t_core *core, int step)
{
	int					i;
	t_wall_lst			*current;

	i = 0;
	current = core->wall_list;
	if (core->select->wall >= 0)
	{
		while (i < core->select->wall && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->wall->t_texture + step < NUM_WALL_TEXTURES)
			current->wall->t_texture += step;
		else
			current->wall->t_texture = 0;
	}
}

void			m_texture_change(t_core *core, int step)
{
	int					i;
	t_wall_lst			*current;

	i = 0;
	current = core->wall_list;
	if (core->select->wall >= 0)
	{
		while (i < core->select->wall && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->wall->m_texture + step < NUM_WALL_TEXTURES)
			current->wall->m_texture += step;
		else
			current->wall->m_texture = 0;
	}
}

void			b_texture_change(t_core *core, int step)
{
	int					i;
	t_wall_lst			*current;

	i = 0;
	current = core->wall_list;
	if (core->select->wall >= 0)
	{
		while (i < core->select->wall && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->wall->b_texture + step < NUM_WALL_TEXTURES)
			current->wall->b_texture += step;
		else
			current->wall->b_texture = 0;
	}
}

void			next_sector_change(t_core *core)
{
	int					i;
	t_wall_lst			*current;

	i = 0;
	current = core->wall_list;
	if (core->select->wall >= 0)
	{
		while (i < core->select->wall && current != NULL)
		{
			i++;
			current = current->next;
		}
		if (current->wall->next_sector + 1 <
				get_nbr_sector(core->sector_list, 0))
			current->wall->next_sector += 1;
		else
			current->wall->next_sector = -1;
	}
}
