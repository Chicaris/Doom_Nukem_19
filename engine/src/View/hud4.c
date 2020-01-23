/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:04:51 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/08 16:04:52 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	display_life(t_core *core)
{
	SDL_Rect		winpos;
	int				i;

	i = 0;
	winpos.x = 55;
	winpos.y = 3;
	winpos.w = 20;
	winpos.h = 50;
	while (i < core->player.life)
	{
		SDL_FillRect(core->sdl.surface, &winpos, 0xff0000);
		winpos.x += 20;
		i++;
	}
	winpos.x = 0;
	winpos.y = 0;
	SDL_BlitSurface(core->level.textures[10], NULL, core->sdl.surface, NULL);
}

void	display_viseur(t_core *core)
{
	SDL_Rect	winpos;
	int			i;

	i = 0;
	winpos.x = WIN_WIDTH / 2 - core->level.textures[60]->w / 2;
	winpos.y = WIN_HEIGHT / 2 - core->level.textures[60]->h / 2;
	SDL_BlitSurface(core->level.textures[60], NULL, core->sdl.surface, &winpos);
}

void	display_hud(t_core *core)
{
	display_life(core);
	display_viseur(core);
	if (core->player.gun[core->player.active_wp].posessed == 1)
		display_gun(core, core->player.active_wp);
}
