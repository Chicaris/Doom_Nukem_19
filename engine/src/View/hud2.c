/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:19 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/08 15:59:22 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	display_you_win(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	SDL_FillRect(core->sdl.surface, NULL, 0xaf0c0c);
	texte = get_texte("YOU WIN", core->level.ttf_path[0], int_to_rgb(WHITE),
		128);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = (WIN_HEIGHT / 2) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Made by cbruno and rgauthie", core->level.ttf_path[0],
		int_to_rgb(WHITE), 16);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = 15 * (WIN_HEIGHT / 16) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	SDL_UpdateWindowSurface(core->sdl.window);
}

void	display_game_over(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	SDL_FillRect(core->sdl.surface, NULL, 0xaf0c0c);
	texte = get_texte("GAME OVER", core->level.ttf_path[0],
		int_to_rgb(WHITE), 128);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = (WIN_HEIGHT / 2) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	texte = get_texte("Made by cbruno and rgauthie", core->level.ttf_path[0],
		int_to_rgb(WHITE), 16);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = 15 * (WIN_HEIGHT / 16) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	SDL_UpdateWindowSurface(core->sdl.window);
}

void	display_play(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	if (core->selected == 0)
	{
		texte = get_texte("PLAY", core->level.ttf_path[0],
			int_to_rgb(WHITE), 128);
		winpos.x = (WIN_WIDTH - texte->w) / 2;
		winpos.y = (WIN_HEIGHT / 3) - (texte->h / 2);
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	}
	else
	{
		texte = get_texte("PLAY", core->level.ttf_path[0],
			int_to_rgb(RED), 64);
		winpos.x = (WIN_WIDTH - texte->w) / 2;
		winpos.y = (WIN_HEIGHT / 3) - (texte->h / 2);
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	}
	SDL_FreeSurface(texte);
}

void	display_quit(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	if (core->selected == 1)
	{
		texte = get_texte("QUIT", core->level.ttf_path[0],
			int_to_rgb(WHITE), 128);
		winpos.x = (WIN_WIDTH - texte->w) / 2;
		winpos.y = 2 * (WIN_HEIGHT / 3) - (texte->h / 2);
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_FreeSurface(texte);
	}
	else
	{
		texte = get_texte("QUIT", core->level.ttf_path[0],
			int_to_rgb(RED), 64);
		winpos.x = (WIN_WIDTH - texte->w) / 2;
		winpos.y = 2 * (WIN_HEIGHT / 3) - (texte->h / 2);
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_FreeSurface(texte);
	}
}

void	display_menu(t_core *core)
{
	SDL_Surface	*texte;
	SDL_Rect	winpos;

	winpos.x = 0;
	winpos.y = 0;
	SDL_BlitSurface(core->level.textures[7], NULL, core->sdl.surface, &winpos);
	display_play(core);
	display_quit(core);
	texte = get_texte("Made by cbruno and rgauthie", core->level.ttf_path[0],
		int_to_rgb(WHITE), 16);
	winpos.x = (WIN_WIDTH - texte->w) / 2;
	winpos.y = 15 * (WIN_HEIGHT / 16) - (texte->h / 2);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
	SDL_UpdateWindowSurface(core->sdl.window);
}
