/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:23:24 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:35:15 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void		menu_player2(t_core *core)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("PLAYER MENU", core->ttf_path[1], int_to_rgb(WHITE), 32);
	winpos.x = MAP_WIDTH + ((WIN_WIDTH - MAP_WIDTH) / 2) - (texte->w / 2);
	winpos.y = 75;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Player position :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(core->player->position[0]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 250;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void			menu_player(t_core *core)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	menu_player2(core);
	texte = get_texte(ft_itoa(core->player->position[1]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(core->player->position[2]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}
