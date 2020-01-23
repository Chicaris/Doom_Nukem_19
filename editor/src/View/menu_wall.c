/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:36:48 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:12:00 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void			title(t_core *core)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("WALL MENU", core->ttf_path[1], int_to_rgb(WHITE), 32);
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
	texte = get_texte("Wall selected :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void			info_wall(t_core *core, t_wall *wall, SDL_Rect winpos,
		SDL_Surface *texte)
{
	texte = get_texte(ft_itoa(core->select->wall), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Next sector :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(wall->next_sector), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Press '+' to change", core->ttf_path[1],
			int_to_rgb(WHITE), 12);
	winpos.x = MAP_WIDTH + 300;
	winpos.y = 200;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void			menu_wall2(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	texte = get_texte("NAN", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void				menu_wall(t_core *core)
{
	t_wall		*wall;
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	title(core);
	if (core->select->sector < 0)
		texte = get_texte("NAN", core->ttf_path[1], int_to_rgb(WHITE), 16);
	else
		texte = get_texte(ft_itoa(core->select->sector), core->ttf_path[1],
				int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	if (core->select->wall < 0)
		menu_wall2(core);
	else
	{
		wall = get_wall(core, core->select->wall);
		info_wall(core, wall, winpos, texte);
		middle(core, wall);
		if (wall->next_sector != -1)
			top_bottom(core, wall);
	}
}
