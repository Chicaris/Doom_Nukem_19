/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:05:04 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 10:38:25 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				draw_flag_select(t_core *core)
{
	int				i;
	t_wall_lst		*current;

	i = 0;
	current = core->wall_list;
	draw_wall_list(core);
	if (core->select->sector >= 0)
		draw_sector_select(core);
	while (current != NULL)
	{
		if (core->select->wall == i)
			draw_wall(core, current->wall, GREEN);
		i++;
		current = current->next;
	}
}

void				draw_wall_select(t_core *core)
{
	int				i;
	t_wall_lst		*current;

	i = 0;
	current = core->wall_list;
	draw_wall_list(core);
	if (core->select->sector >= 0)
		draw_sector_select(core);
	while (current != NULL)
	{
		if (core->select->wall == i)
			draw_wall(core, current->wall, GREEN);
		i++;
		current = current->next;
	}
}

void				draw_player(t_core *core)
{
	int			point[2];

	point[0] = core->player->position[0] * STEP_GRID + core->grid->center[0];
	point[1] = core->player->position[1] * STEP_GRID + core->grid->center[1];
	draw_circle_bres(core->sdl.surface, point, 3, RED);
}

void				draw_monster(t_core *core)
{
	int				i;
	t_monster_lst	*curr;
	int				point[2];

	i = 0;
	curr = core->monster_list;
	while (curr != NULL)
	{
		point[0] = curr->monster->origin[0] * STEP_GRID + core->grid->center[0];
		point[1] = curr->monster->origin[1] * STEP_GRID + core->grid->center[1];
		if (i != core->select->monster)
			draw_circle_bres(core->sdl.surface, point, 3, YELLOW);
		else
			draw_circle_bres(core->sdl.surface, point, 3, RED);
		i++;
		curr = curr->next;
	}
}

void				draw_sector_select(t_core *core)
{
	int			start;
	int			stop;
	int			i;
	t_sector	*sector;
	t_wall_lst	*current;

	i = 0;
	current = core->wall_list;
	draw_wall_list(core);
	if (core->select->sector != -1)
	{
		sector = get_sector(core, core->select->sector);
		start = sector->start_wall;
		stop = start + sector->num_walls;
		while (current != NULL)
		{
			if (i >= start && i < stop)
				draw_wall(core, current->wall, RED);
			i++;
			current = current->next;
		}
	}
}
