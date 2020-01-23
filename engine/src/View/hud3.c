/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:01:43 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/14 12:26:59 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	display_inventory3(t_core *core, SDL_Surface *texte, SDL_Rect winpos,
		SDL_Color color)
{
	winpos.x = winpos.x + texte->w + 10;
	texte = get_texte(ft_itoa(core->player.inventory[2].quantity),
			core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = 30;
	winpos.y = 225;
	texte = get_texte("Key :", core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = winpos.x + texte->w + 10;
	texte = get_texte(ft_itoa(core->player.inventory[3].quantity),
			core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void	display_inventory2(t_core *core, SDL_Surface *texte, SDL_Rect winpos,
		SDL_Color color)
{
	winpos.x = 30;
	winpos.y = 195;
	texte = get_texte("Demon amminition :", core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = winpos.x + texte->w + 10;
	texte = get_texte(ft_itoa(core->player.inventory[1].quantity),
		core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = 30;
	winpos.y = 210;
	texte = get_texte("Hand amminition :", core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	display_inventory3(core, texte, winpos, color);
}

void	display_inventory(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;
	SDL_Color	color;

	color = int_to_rgb(WHITE);
	winpos.x = 30;
	winpos.y = 150;
	texte = get_texte("INVENTORY", core->level.ttf_path[0], color, 32);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.y = 180;
	texte = get_texte("Rifle ammunition :", core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = winpos.x + texte->w + 10;
	texte = get_texte(ft_itoa(core->player.inventory[0].quantity),
			core->level.ttf_path[0], color, 12);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	display_inventory2(core, texte, winpos, color);
}

void	display_pause_menu(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	SDL_FillRect(core->sdl.surface, NULL, 0xaf0c0c);
	display_play(core);
	display_quit(core);
	texte = get_texte("Made by cbruno and rgauthie", core->level.ttf_path[0],
		int_to_rgb(RED), 10);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = 15 * (WIN_HEIGHT / 16) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	display_inventory(core);
	SDL_UpdateWindowSurface(core->sdl.window);
}
