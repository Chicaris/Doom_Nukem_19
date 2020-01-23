/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:48:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/19 10:55:31 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				update_event(t_core *core)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
					event.key.keysym.sym == SDLK_ESCAPE))
		{
			free_all(core);
			exit(0);
		}
		if (event.type == SDL_KEYDOWN)
			key_down(core, event.key);
		if (event.type == SDL_MOUSEBUTTONDOWN)
			mouse_button(core, event.button);
	}
}

static void			draw_select2(t_core *core)
{
	if (core->option == wall_select)
	{
		if (core->wall_list != NULL)
		{
			menu_wall(core);
			draw_wall_select(core);
		}
	}
	if (core->option == flag_mode)
		draw_flag_select(core);
	if (core->option == sector_select)
	{
		if (core->sector_list != NULL)
		{
			menu_sector(core);
			draw_sector_select(core);
		}
	}
}

static void			draw_select(t_core *core)
{
	draw_select2(core);
	if (core->option == player)
	{
		menu_player(core);
		draw_player(core);
	}
	if (core->option == monster_mode)
	{
		if (core->monster_list != NULL)
		{
			menu_monster(core);
			draw_monster(core);
		}
	}
	if (core->option == objet_mode)
	{
		if (core->pickup_list != NULL)
		{
			menu_objet(core);
			draw_objet(core);
		}
	}
}

void				paint(t_core *core)
{
	int		point[2];

	SDL_FillRect(core->sdl.surface, NULL, 0x000000);
	draw_grid(core);
	draw_map_border(core->sdl.surface, MAP_WIDTH, BLUE);
	draw_circle_bres(core->sdl.surface, core->grid->center, 3, GREEN);
	draw_wall_list(core);
	if (core->option == draw)
	{
		if (core->grid->tst != 0)
		{
			point[0] = core->grid->first_click[0] * STEP_GRID +
				core->grid->center[0];
			point[1] = core->grid->first_click[1] * STEP_GRID +
				core->grid->center[1];
			draw_circle_bres(core->sdl.surface, point, 3, PURPLE);
		}
	}
	draw_select(core);
	print_controller(core);
	SDL_UpdateWindowSurface(core->sdl.window);
}

void				mainloop(t_core *core)
{
	paint(core);
	while (1)
		update_event(core);
}
