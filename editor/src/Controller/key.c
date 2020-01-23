/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:27:01 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 11:32:33 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		sector_input(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_e)
	{
		core->select->sector = -1;
		core->select->wall = -1;
		core->option = sector_select;
	}
	if (core->option == sector_select)
	{
		if (key.keysym.sym == SDLK_KP_7)
			ceil_change(core, 0.1);
		if (key.keysym.sym == SDLK_KP_8)
			ceil_change(core, -0.1);
		if (key.keysym.sym == SDLK_KP_4)
			floor_change(core, 0.1);
		if (key.keysym.sym == SDLK_KP_5)
			floor_change(core, -0.1);
	}
}

void		wall_input(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_w)
	{
		core->select->sector = -1;
		core->select->wall = -1;
		core->option = wall_select;
	}
	if (core->option == wall_select)
	{
		if (key.keysym.sym == SDLK_u)
			undo_last_wall(core);
		if (key.keysym.sym == SDLK_KP_PLUS)
			next_sector_change(core);
	}
}

void		flag_input(t_core *core, SDL_KeyboardEvent key)
{
	t_flag	flag;
	t_wall	*wall;

	if (key.keysym.sym == SDLK_f)
	{
		core->select->sector = -1;
		core->select->wall = -1;
		core->option = flag_mode;
	}
	if (core->option == flag_mode)
	{
		if (key.keysym.sym == SDLK_x)
		{
			if (core->select->wall >= 0)
			{
				wall = get_wall(core, core->select->wall);
				flag = (t_flag) {91, {1.0, 1.0, 2.0}, core->textures[91]->w,
					core->textures[91]->h};
				add_flag(core, core->select->wall, &flag);
			}
		}
	}
}

void		key_down2(t_core *core, SDL_KeyboardEvent key)
{
	if (key.keysym.sym == SDLK_q)
		core->grid->tst = 0;
	if (key.keysym.sym == SDLK_s)
	{
		if (write_file(core) != true)
		{
			ft_putstr("write failed\n");
			free_all(core);
			exit(0);
		}
	}
	if (key.keysym.sym == SDLK_d)
		core->option = draw;
	if (key.keysym.sym == SDLK_u)
		if (core->option == draw)
			undo_last_wall(core);
	if (key.keysym.sym == SDLK_p)
		core->option = player;
}

void		key_down(t_core *core, SDL_KeyboardEvent key)
{
	move(core, key);
	sector_input(core, key);
	wall_input(core, key);
	flag_input(core, key);
	if (key.keysym.sym == SDLK_m)
		core->option = monster_mode;
	if (key.keysym.sym == SDLK_o)
		core->option = objet_mode;
	if (core->option == monster_mode)
		if (key.keysym.sym == SDLK_u)
			undo_last_monster(core);
	if (core->option == objet_mode)
	{
		if (key.keysym.sym == SDLK_u)
			undo_last_pickup(core);
		if (key.keysym.sym == SDLK_KP_PLUS)
			pickup_id_change(core, 1);
	}
	key_down2(core, key);
	paint(core);
}
