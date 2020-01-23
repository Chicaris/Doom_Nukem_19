/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_sector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:05:17 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:20:47 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void			floor_ceil(t_core *core, t_sector *sector)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("Floor height :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 200;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 200;
	write_float(core, winpos, sector->floor_height);
	texte = get_texte("Ceil height :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 225;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 225;
	write_float(core, winpos, sector->ceiling_height);
}

static void			menu_sector2(t_core *core, t_sector *sector)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte(ft_itoa(core->select->sector), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Start wall :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(sector->start_wall), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void			menu_sector3(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("SECTOR MENU", core->ttf_path[1],
			int_to_rgb(WHITE), 32);
	winpos.x = MAP_WIDTH + ((WIN_WIDTH - MAP_WIDTH) / 2) - (texte->w / 2);
	winpos.y = 75;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Sector selected :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void			menu_sector4(t_core *core, t_sector *sector)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	menu_sector2(core, sector);
	texte = get_texte("Numbers of walls :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(sector->num_walls), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	floor_ceil(core, sector);
	textures_sector(core, sector);
}

void				menu_sector(t_core *core)
{
	t_sector	*sector;
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	menu_sector3(core);
	if (core->select->sector < 0)
	{
		texte = get_texte("NAN", core->ttf_path[1], int_to_rgb(WHITE), 16);
		winpos.x = MAP_WIDTH + 350;
		winpos.y = 125;
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_FreeSurface(texte);
	}
	else
	{
		sector = get_sector(core, core->select->sector);
		if (sector != NULL)
			menu_sector4(core, sector);
	}
}
