/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:53:23 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:53:24 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void			in_map2(t_core *core, float x, float y)
{
	if (core->option == wall_select)
		if (core->select->sector >= 0)
			core->select->wall = get_closest_wall(core, core->wall_list, x, y);
	if (core->option == flag_mode)
		if (core->select->sector >= 0)
			core->select->wall = get_closest_wall(core, core->wall_list, x, y);
	if (core->option == sector_select)
		core->select->sector = get_closest_sector(core, core->sector_list,
				x, y);
	if (core->option == player)
		set_player(core, x, y);
}

void			in_map(t_core *core, float x, float y)
{
	t_monster	*monster;
	t_pickup	*pickup;

	draw_option(core, x, y);
	in_map2(core, x, y);
	if (core->option == monster_mode)
	{
		monster = init_monster(core, x, y);
		if (is_monster_ok(core, monster) == true)
		{
			if (add_monster(core, monster) == false)
				error_msg("add_monster failed\n");
		}
		else
			free(monster);
	}
	if (core->option == objet_mode)
	{
		pickup = init_pickup(core, x, y);
		if (is_pickup_ok(core, pickup) == true)
			add_pickup(core, pickup);
		else
			free(pickup);
	}
}
