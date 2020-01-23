/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:49:20 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:49:21 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		free_sdl(t_core *core)
{
	if (core->sdl.surface != NULL)
		SDL_FreeSurface(core->sdl.surface);
	if (core->sdl.window != NULL)
		SDL_DestroyWindow(core->sdl.window);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

void		free_textures(t_core *core)
{
	int		i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (core->textures[i] != NULL)
			SDL_FreeSurface(core->textures[i]);
		i++;
	}
}

void		free_sector_lst(t_sector_lst *sector_list)
{
	t_sector_lst *tmp;

	while (sector_list != NULL)
	{
		tmp = sector_list->next;
		if (sector_list->sector != NULL)
			free(sector_list->sector);
		free(sector_list);
		sector_list = tmp;
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

void		free_wall_lst(t_wall_lst *wall_list)
{
	t_wall_lst		*tmp;

	while (wall_list != NULL)
	{
		tmp = wall_list->next;
		if (wall_list->wall != NULL)
			free_wall(wall_list->wall);
		free(wall_list);
		wall_list = tmp;
	}
}
