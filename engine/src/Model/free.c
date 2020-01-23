/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:39:13 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 14:42:49 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		free_lines(t_line *lines)
{
	while (lines != NULL)
	{
		free(lines);
		lines = lines->next;
	}
}

void		free_wall_list(t_wall_list *wall_list)
{
	if (wall_list->wall.flag != NULL)
		free(wall_list->wall.flag);
	if (wall_list->lines != NULL)
		free_lines(wall_list->lines);
}

void		free_world(t_core *core)
{
	while (core->world != NULL)
	{
		while (core->world->wall_list != NULL)
		{
			free_wall_list(core->world->wall_list);
			free(core->world->wall_list);
			core->world->wall_list = core->world->wall_list->next;
		}
		free(core->world);
		core->world = core->world->next;
	}
}

void		free_player(t_core *core)
{
	if (core->player.inventory != NULL)
		free(core->player.inventory);
	//if (core->player.gun != NULL)
	//	free(core->player.gun);
}

void		free_all(t_core *core)
{
	if (core->file != NULL)
		free(core->file);
	free_level_data(core);
	free_world(core);
	//free_player(core);
	//free(core->item_ls.item_list);
	free_sdl(core);
}
