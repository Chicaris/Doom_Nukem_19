/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:13:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:40:07 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void		textures(t_core *core, t_monster *monster)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("Monster texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 250;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[monster->texture],
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

static void		position(t_core *core, t_monster *monster)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("Monster position :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 175;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(monster->origin[0]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 300;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(monster->origin[1]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(monster->origin[2]), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 400;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

static void		menu_monster2(t_core *core, t_monster *monster)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte(ft_itoa(core->select->monster), core->ttf_path[1],
				int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Sector_idx :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte(ft_itoa(monster->sector_idx), core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 150;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	position(core, monster);
	textures(core, monster);
}

static void		menu_monster3(t_core *core)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("MONSTER MENU", core->ttf_path[1], int_to_rgb(WHITE), 32);
	winpos.x = MAP_WIDTH + ((WIN_WIDTH - MAP_WIDTH) / 2) - (texte->w / 2);
	winpos.y = 75;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Monster selected :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 125;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void			menu_monster(t_core *core)
{
	t_monster		*monster;
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	menu_monster3(core);
	if (core->select->monster < 0)
	{
		texte = get_texte("NAN", core->ttf_path[1], int_to_rgb(WHITE), 16);
		winpos.x = MAP_WIDTH + 350;
		winpos.y = 125;
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_FreeSurface(texte);
	}
	else
	{
		monster = get_monster(core, core->select->monster);
		if (monster != NULL)
			menu_monster2(core, monster);
	}
}
