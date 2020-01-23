/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:20:52 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 15:01:21 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		update_event2(t_core *core, SDL_Event event, int user_counter)
{
	if (event.type == SDL_USEREVENT)
	{
		user_counter++;
		if (user_counter >= FPS_DT)
		{
			mouse_update(core);
			user_counter = 0;
			if (core->game_status == game)
			{
				move(core);
				check_pickup_proximity_lst(core);
				door_move(core);
				move_monster_list(core);
				paint(core);
			}
			else if (core->game_status == menu)
				display_menu(core);
			else if (core->game_status == pause_menu)
				display_pause_menu(core);
			else if (core->game_status == game_over)
				display_game_over(core);
			else if (core->game_status == you_win)
				display_you_win(core);
		}
	}
}

void		update_event(t_core *core)
{
	SDL_Event	event;
	int			user_counter;

	user_counter = FPS_DT;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT ||
			(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			error_msg(core, "QUIT\n");
		if (event.type == SDL_KEYDOWN)
			key_down(core, event.key);
		if (event.type == SDL_MOUSEBUTTONDOWN)
			mouse_down(core, event.button);
		if (event.type == SDL_MOUSEBUTTONUP)
			mouse_up(core, event.button);
		if (event.type == SDL_MOUSEMOTION)
			mouse_motion(core, event);
		if (event.type == SDL_MOUSEWHEEL)
			mouse_wheel(core, event.wheel);
		update_event2(core, event, user_counter);
	}
}

uint32_t	timer_callback(Uint32 intervalle, void *param)
{
	t_core		*core;
	SDL_Event	user_event;

	core = (t_core *)param;
	user_event.type = SDL_USEREVENT;
	user_event.user.code = 0;
	user_event.user.data1 = NULL;
	user_event.user.data2 = NULL;
	SDL_PushEvent(&user_event);
	return (intervalle);
}

void		mainloop(t_core *core)
{
	core->timer = SDL_AddTimer(100, timer_callback, core);
	print_menu();
	while (1)
	{
		update_event(core);
	}
}
