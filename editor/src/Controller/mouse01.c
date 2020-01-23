/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:02:31 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:28:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void			is_wall_option(t_core *core, SDL_MouseButtonEvent event)
{
	if (core->option == wall_select && core->select->wall >= 0)
	{
		if (event.x >= 1135 && event.x < 1150 && event.y >= 325 &&
				event.y < 340)
			t_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 325 &&
				event.y < 340)
			t_texture_change(core, 1);
		if (event.x >= 1135 && event.x < 1150 && event.y >= 550 &&
				event.y < 565)
			m_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 550 &&
				event.y < 560)
			m_texture_change(core, 1);
		if (event.x >= 1135 && event.x < 1150 && event.y >= 775 &&
				event.y < 790)
			b_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 775 &&
				event.y < 790)
			b_texture_change(core, 1);
	}
}

void			is_sector_option(t_core *core, SDL_MouseButtonEvent event)
{
	if (core->option == sector_select && core->select->sector >= 0)
	{
		if (event.x >= 1135 && event.x < 1150 && event.y >= 350 &&
				event.y < 365)
			floor_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 350 &&
				event.y < 365)
			floor_texture_change(core, 1);
		if (event.x >= 1135 && event.x < 1150 && event.y >= 575 &&
				event.y < 590)
			ceil_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 575 &&
				event.y < 590)
			ceil_texture_change(core, 1);
	}
}

void			is_monster_option(t_core *core, SDL_MouseButtonEvent event)
{
	if (core->option == monster_mode && core->select->monster >= 0)
	{
		if (event.x >= 1135 && event.x < 1150 && event.y >= 350 &&
				event.y < 365)
			monster_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 350 &&
				event.y < 365)
			monster_texture_change(core, 1);
	}
}

void			is_pickup_option(t_core *core, SDL_MouseButtonEvent event)
{
	if (core->option == objet_mode && core->select->pickup >= 0)
	{
		if (event.x >= 1135 && event.x < 1150 && event.y >= 350 &&
				event.y < 365)
			pickup_texture_change(core, -1);
		if (event.x >= 1345 && event.x < 1360 && event.y >= 350 &&
				event.y < 365)
			pickup_texture_change(core, 1);
	}
}

void			is_right_button(t_core *core, float x, float y)
{
	if (core->option == wall_select)
	{
		core->select->wall = -1;
		core->select->sector = get_closest_sector(core,
				core->sector_list, x, y);
	}
	if (core->option == flag_mode)
	{
		core->select->wall = -1;
		core->select->sector = get_closest_sector(core,
				core->sector_list, x, y);
	}
	if (core->option == monster_mode)
		core->select->monster = get_closest_monster(
				core->monster_list, x, y);
	if (core->option == objet_mode)
		core->select->pickup = get_closest_pickup(core->pickup_list, x, y);
}
