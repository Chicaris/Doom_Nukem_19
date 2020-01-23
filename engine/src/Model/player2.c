/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:28:35 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/14 16:07:46 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	init_weapon3(t_core *core, t_weapon *gun)
{
	gun[2].w_id = 2;
	gun[2].w_status = 0;
	gun[2].posessed = 1;
	gun[2].w_rof = 1;
	gun[2].w_range = 8;
	gun[2].w_mag_size = 11;
	gun[2].w_magazine = 11;
	gun[2].w_fire_spr = 0;
	gun[2].w_reload_spr = 0;
	gun[2].w_rload_spd = 3;
	gun[2].w_empty_spr = 0;
	gun[2].rest_sprs = 46;
	gun[2].fire_sprs = 47;
	gun[2].empty_sprs = 49;
	gun[2].rload_sprs = 51;
	gun[2].fire_spr_nbr = 4;
	gun[2].empty_spr_nbr = 1;
	gun[2].rload_spr_nbr = 8;
	core->player.gun = gun;
}

void	init_weapon2(t_core *core, t_weapon *gun)
{
	gun[1].w_id = 1;
	gun[1].w_status = 0;
	gun[1].posessed = 0;
	gun[1].w_rof = 1;
	gun[1].w_range = 15;
	gun[1].w_mag_size = 10;
	gun[1].w_magazine = 10;
	gun[1].w_fire_spr = 0;
	gun[1].w_reload_spr = 0;
	gun[1].w_rload_spd = 2;
	gun[1].w_empty_spr = 0;
	gun[1].rest_sprs = 27;
	gun[1].fire_sprs = 28;
	gun[1].empty_sprs = 31;
	gun[1].rload_sprs = 37;
	gun[1].fire_spr_nbr = 3;
	gun[1].empty_spr_nbr = 6;
	gun[1].rload_spr_nbr = 9;
	init_weapon3(core, gun);
}

t_bool	init_weapon(t_core *core)
{
	t_weapon *gun;

	if (!(gun = (t_weapon *)malloc(sizeof(t_weapon) * 3)))
		return (false);
	gun[0].w_id = 0;
	gun[0].w_status = 0;
	gun[0].posessed = 0;
	gun[0].w_rof = 1;
	gun[0].w_range = 10;
	gun[0].w_mag_size = 30;
	gun[0].w_magazine = 30;
	gun[0].w_fire_spr = 0;
	gun[0].w_reload_spr = 0;
	gun[0].w_rload_spd = 3;
	gun[0].w_empty_spr = 0;
	gun[0].rest_sprs = 20;
	gun[0].fire_sprs = 21;
	gun[0].empty_sprs = 20;
	gun[0].rload_sprs = 23;
	gun[0].fire_spr_nbr = 2;
	gun[0].empty_spr_nbr = 1;
	gun[0].rload_spr_nbr = 5;
	init_weapon2(core, gun);
	return (true);
}

t_bool	init_player(t_core *core)
{
	t_player	player;
	t_item		*invent;
	int			i;

	i = 0;
	if (!(invent = (t_item *)malloc(sizeof(t_item) * ITEM_NBR - 4)))
		error_msg(core, "Could not malloc inventory");
	player.active_wp = 0;
	player.inventory = invent;
	player.life = 11;
	player.inventory[0].item_id = 0;
	player.inventory[0].item_name = "rifle ammo";
	player.inventory[0].quantity = 30;
	player.inventory[1].item_id = 1;
	player.inventory[1].item_name = "demon ammo";
	player.inventory[1].quantity = 30;
	player.inventory[2].item_id = 2;
	player.inventory[2].item_name = "hand gun ammo";
	player.inventory[2].quantity = 40;
	player.inventory[3].item_id = 3;
	player.inventory[3].item_name = "Sacred Key";
	player.inventory[3].quantity = 0;
	ft_memcpy(&core->player, &player, sizeof(t_player));
	return (true);
}

void	floor_is_lava(t_core *core)
{
	if (core->level.sectors[core->sector_in].floor_texture == 62)
		if (core->camera.origin[2] <
			core->level.sectors[core->sector_in].floor_height + ZMIN + 10)
			update_life(core, -1);
}
