/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_objet01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:56:49 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:56:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		textures_pickup(t_core *core, t_pickup *pickup)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("Pickup texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 250;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[pickup->texture],
			MAP_WIDTH + 175, 275);
	texte = get_texte("-", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 140;
	winpos.y = 350;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("+", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 350;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}
