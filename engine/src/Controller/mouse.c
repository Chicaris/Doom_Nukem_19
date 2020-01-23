/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:47:21 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 12:32:03 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	mouse_down(t_core *core, SDL_MouseButtonEvent event)
{
	if ((event.button == SDL_BUTTON_LEFT) || (event.button == SDL_BUTTON_RIGHT))
		core->mouse.button = event.button;
}

void	mouse_up(t_core *core, SDL_MouseButtonEvent event)
{
	if ((event.button == SDL_BUTTON_LEFT) || (event.button == SDL_BUTTON_RIGHT))
		core->mouse.button = 0;
}

void	menu_click(t_core *core)
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

void	mouse_update(t_core *core)
{
	if (core->game_status == game)
		if (core->mouse.button == SDL_BUTTON_LEFT &&
				core->player.gun[core->player.active_wp].posessed == 1)
			fire(core);
	if (core->game_status == menu || core->game_status == pause_menu)
		if (core->mouse.button == SDL_BUTTON_LEFT)
			menu_click(core);
}

void	mouse_wheel(t_core *core, SDL_MouseWheelEvent event)
{
	if (event.y > 0)
		change_weapon(core, 1);
	if (event.y < 0)
		change_weapon(core, -1);
}
