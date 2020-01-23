/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:28:37 by hde-moff          #+#    #+#             */
/*   Updated: 2019/11/18 14:13:17 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_bool	sdl_init2(t_core *core, t_sdl sdl)
{
	ft_memset(sdl.surface->pixels, 0, WIN_HEIGHT * sdl.surface->pitch);
	if (TTF_Init() == -1)
	{
		ft_putstr("TTF_Init failed\n");
		return (false);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
			1024) == -1)
	{
		ft_putstr("Error: Mix_OpenAudio\n");
		return (false);
	}
	if (SDL_SetRelativeMouseMode(SDL_FALSE) == -1)
		error_msg(core, "Couldn't get mouse\n");
	SDL_WarpMouseInWindow(sdl.window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	sdl.x_center = WIN_WIDTH / 2;
	sdl.y_center = WIN_HEIGHT / 2;
	sdl.x_min = -sdl.x_center;
	sdl.x_max = sdl.x_center;
	sdl.y_min = -sdl.y_center;
	sdl.y_max = sdl.y_center;
	ft_memcpy(&core->sdl, &sdl, sizeof(t_sdl));
	return (true);
}

t_bool	sdl_init(t_core *core)
{
	t_sdl	sdl;

	ft_memset(&sdl, 0, sizeof(sdl));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO |
			SDL_INIT_TIMER))
	{
		ft_putstr("Couldn't init SDL\n");
		return (false);
	}
	sdl.window = SDL_CreateWindow("doom-nukem", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT,
			SDL_WINDOW_INPUT_FOCUS);
	if (sdl.window == NULL)
	{
		ft_putstr("Couldn't create SDL window\n");
		return (false);
	}
	sdl.surface = SDL_GetWindowSurface(sdl.window);
	if (sdl.surface == NULL)
	{
		ft_putstr("Couldn't create SDL surface\n");
		return (false);
	}
	return (sdl_init2(core, sdl));
}
