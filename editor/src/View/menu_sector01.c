/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_sector01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:08:53 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 16:10:53 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				write_float(t_core *core, SDL_Rect pos, float dest)
{
	SDL_Surface	*texte;

	texte = get_texte(ft_itoa(dest), core->ttf_path[1], int_to_rgb(WHITE), 16);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &pos);
	SDL_FreeSurface(texte);
	pos.x = pos.x + texte->w;
	texte = get_texte(".", core->ttf_path[1], int_to_rgb(WHITE), 16);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &pos);
	SDL_FreeSurface(texte);
	pos.x = pos.x + texte->w;
	texte = get_texte(ft_itoa((dest - (int)(dest)) * 100), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &pos);
	SDL_FreeSurface(texte);
}

static void			textures2(t_core *core, t_sector *sector)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("Floor texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 250;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[sector->floor_texture],
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

void				textures_sector(t_core *core, t_sector *sector)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	textures2(core, sector);
	texte = get_texte("Ceil texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 475;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[sector->ceiling_texture],
			MAP_WIDTH + 175, 500);
	texte = get_texte("-", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 140;
	winpos.y = 575;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("+", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 575;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}
