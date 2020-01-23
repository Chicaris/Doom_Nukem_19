/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_wall01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:06:49 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 16:11:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void			top_bottom2(t_core *core, t_wall *wall)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("Top texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 225;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[wall->t_texture], MAP_WIDTH + 175, 250);
	texte = get_texte("-", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 140;
	winpos.y = 325;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("+", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 325;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void				top_bottom(t_core *core, t_wall *wall)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	top_bottom2(core, wall);
	texte = get_texte("Bottom texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 675;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[wall->b_texture], MAP_WIDTH + 175, 700);
	texte = get_texte("-", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 140;
	winpos.y = 775;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("+", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 775;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}

void				middle(t_core *core, t_wall *wall)
{
	SDL_Surface		*texte;
	SDL_Rect		winpos;

	texte = get_texte("Middle texture :", core->ttf_path[1],
			int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 50;
	winpos.y = 450;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	draw_texture(core, core->textures[wall->m_texture], MAP_WIDTH + 175, 475);
	texte = get_texte("-", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 140;
	winpos.y = 550;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("+", core->ttf_path[1], int_to_rgb(WHITE), 16);
	winpos.x = MAP_WIDTH + 350;
	winpos.y = 550;
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}
