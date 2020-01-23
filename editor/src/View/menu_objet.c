/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_objet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:19:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:47:03 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void		position(t_core *core, t_pickup *pickup)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("Pickup position :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(pickup->center[0]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 250;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(pickup->center[1]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(pickup->center[2]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void		menu_objet2(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("PICKUP MENU", core->ttf_path[1], int_to_rgb(WHITE), 32);
	winpos.x = MAP_WIDTH + ((WIN_WIDTH - MAP_WIDTH) / 2) - (texte->w / 2);
	winpos.y = 75;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Pickup selected :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void		menu_objet4(t_core *core, t_pickup *pickup)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte(ft_itoa(pickup->sector_idx), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("ID", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 200;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(pickup->item_id), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	winpos.y = 200;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void		menu_objet3(t_core *core, t_pickup *pickup)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	menu_objet4(core, pickup);
	texte = get_texte(ft_itoa(core->select->pickup), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Sector_idx :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void			menu_objet(t_core *core)
{
	t_pickup	*pickup;
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	menu_objet2(core);
	if (core->select->pickup < 0)
	{
		texte = get_texte("NAN", core->ttf_path[1], int_to_rgb(WHITE), 16);
		winpos.x = MAP_WIDTH + 300;
		winpos.y = 125;
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_FreeSurface(texte);
	}
	else
	{
		pickup = get_pickup(core, core->select->pickup);
		if (pickup != NULL)
		{
			menu_objet3(core, pickup);
			position(core, pickup);
			textures_pickup(core, pickup);
		}
	}
}
