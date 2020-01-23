/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:05:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 15:05:35 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		free_sdl(t_core *core)
{
	SDL_RemoveTimer(core->timer);
	if (core->sdl.surface != NULL)
		SDL_FreeSurface(core->sdl.surface);
	if (core->sdl.window != NULL)
		SDL_DestroyWindow(core->sdl.window);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

void		free_monster_list(t_monster_lst *monster_list)
{
	t_monster_lst	*tmp;

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

void		free_wall(t_wall *wall)
{
	if (wall != NULL)
	{
		if (wall->flag != NULL)
			free(wall->flag);
		free(wall);
	}
}

void		free_level_data(t_core *core)
{
	unsigned int			i;

	if (core->level.sectors != NULL)
		free(core->level.sectors);
	if (core->level.walls != NULL)
		free(core->level.walls);
	if (core->level.textures != NULL)
		free(core->level.textures);
	if (core->level.samples != NULL)
	{
		i = 0;
		while (i < core->level.num_audio)
			Mix_FreeChunk(core->level.samples[i++]);
		free(core->level.samples);
	}
	if (core->level.monster_list != NULL)
		free_monster_list(core->level.monster_list);
	if (core->level.pickup_list != NULL)
		free_pickup_list(core->level.pickup_list);
}
