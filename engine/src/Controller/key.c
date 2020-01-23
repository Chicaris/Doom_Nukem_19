/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:27:01 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 16:42:18 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		key_down4(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_m)
	{
		core->music_status ^= DEBUG_FDF_MASK;
		if (core->music_status == DEBUG_FDF_MASK)
			Mix_Resume(-1);
		else
			Mix_Pause(-1);
	}
	if (key.keysym.sym == SDLK_t)
	{
		if (core->game_status == pause_menu)
		{
			core->game_status = game;
			if (SDL_SetRelativeMouseMode(SDL_TRUE) == -1)
				error_msg(core, "Couldn't get mouse\n");
		}
		else if (core->game_status == game)
		{
			core->game_status = pause_menu;
			if (SDL_SetRelativeMouseMode(SDL_FALSE) == -1)
				error_msg(core, "Couldn't get mouse\n");
		}
	}
}

void		key_down3(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_e)
		if (core->player.inventory[3].quantity > 0)
			core->door_status ^= DEBUG_FDF_MASK;
	if (key.keysym.sym == SDLK_s)
		if (core->game_status == game)
			camera_step(&core->camera, -VSTEP);
	if (key.keysym.sym == SDLK_a)
		straff_key(&core->camera, -VSTEP);
	if (key.keysym.sym == SDLK_d)
		straff_key(&core->camera, VSTEP);
	if (key.keysym.sym == SDLK_SPACE)
		core->camera.speed[2] = VJUMP;
	if (key.keysym.sym == SDLK_k)
		core->fly_mode ^= DEBUG_FDF_MASK;
	if (key.keysym.sym == SDLK_r)
		reload_gun(core);
	if (key.keysym.sym == SDLK_c)
		core->sky_status ^= DEBUG_FDF_MASK;
	if (key.keysym.sym == SDLK_LSHIFT)
		core->step_status ^= DEBUG_FDF_MASK;
	key_down4(core, key);
}

void		key_return(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_RETURN)
	{
		if (core->game_status == menu || core->game_status == pause_menu)
		{
			if (core->selected == 0)
			{
				core->game_status = game;
				if (SDL_SetRelativeMouseMode(SDL_TRUE) == -1)
					error_msg(core, "Couldn't get mouse\n");
			}
			else
			{
				free_all(core);
				exit(0);
			}
		}
	}
	if (key.keysym.sym == SDLK_SPACE)
		core->camera.speed[2] = VJUMP;
	if (key.keysym.sym == SDLK_l)
		core->debug ^= DEBUG_FDF_MASK;
	if (key.keysym.sym == SDLK_k)
		core->fly_mode ^= DEBUG_FDF_MASK;
}

void		key_move(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_w)
		camera_step(&core->camera, VSTEP);
	if (key.keysym.sym == SDLK_s)
		camera_step(&core->camera, -VSTEP);
	if (key.keysym.sym == SDLK_a)
		straff_key(&core->camera, -VSTEP);
	if (key.keysym.sym == SDLK_d)
		straff_key(&core->camera, VSTEP);
}

void		key_arrow(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_LEFT)
		rotate_world_z(&core->camera, M_PI / 72);
	if (key.keysym.sym == SDLK_RIGHT)
		rotate_world_z(&core->camera, -M_PI / 72);
	if (key.keysym.sym == SDLK_UP)
	{
		if (core->game_status == menu || core->game_status == pause_menu)
			core->selected--;
		if (core->selected < 0)
			core->selected = 1;
		else
			rotate_camera_right(&core->camera, M_PI / 72);
	}
	if (key.keysym.sym == SDLK_DOWN)
	{
		if (core->game_status == menu || core->game_status == pause_menu)
		{
			core->selected++;
			if (core->selected > 1)
				core->selected = 0;
		}
		else
			rotate_camera_right(&core->camera, -M_PI / 72);
	}
}
