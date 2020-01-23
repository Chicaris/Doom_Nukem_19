/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:55:49 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:52:38 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool		sdl_init(t_sdl *sdl)
{
	ft_memset(sdl, 0, sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO |
				SDL_INIT_TIMER))
		return (false);
	sdl->window = SDL_CreateWindow("doom-nukem", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT,
			SDL_WINDOW_INPUT_FOCUS);
	if (sdl->window == NULL)
		return (false);
	sdl->surface = SDL_GetWindowSurface(sdl->window);
	if (TTF_Init() == -1)
		error_msg("Error : TTF_Init\n");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)
			== -1)
		return (false);
	return (true);
}
