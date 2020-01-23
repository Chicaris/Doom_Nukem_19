/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:46:34 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:23:55 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		free_monster_list(t_monster_lst *monster_list)
{
	t_monster_lst *tmp;

	while (monster_list != NULL)
	{
		tmp = monster_list->next;
		if (monster_list->monster != NULL)
			free(monster_list->monster);
		free(monster_list);
		monster_list = tmp;
	}
}

void		free_pickup_list(t_pickup_lst *pickup_list)
{
	t_pickup_lst *tmp;

	while (pickup_list != NULL)
	{
		tmp = pickup_list->next;
		if (pickup_list->pickup != NULL)
			free(pickup_list->pickup);
		free(pickup_list);
		pickup_list = tmp;
	}
}

void		free_audio(t_core *core)
{
	int		i;

	i = 0;
	while (i < NUM_AUDIO)
	{
		Mix_FreeChunk(core->audio[i]);
		i++;
	}
}

void		free_ttf(t_core *core)
{
	int		i;

	i = 0;
	while (i < NUM_TTF)
	{
		if (core->ttf_path[i] != NULL)
			free(core->ttf_path[i]);
		i++;
	}
}

void		free_all(t_core *core)
{
	if (core->file != NULL)
		free(core->file);
	free_textures(core);
	free_sector_lst(core->sector_list);
	free_wall_lst(core->wall_list);
	free(core->grid);
	free(core->select);
	free(core->player);
	free_monster_list(core->monster_list);
	free_pickup_list(core->pickup_list);
	free_audio(core);
	free_ttf(core);
	free_sdl(core);
}
