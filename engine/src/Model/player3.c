/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:35:09 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/09 17:39:39 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	reload_gun2(t_core *core, int active)
{
	if (core->player.gun[active].w_mag_size <=
		core->player.inventory[active].quantity)
	{
		core->player.inventory[active].quantity -=
			core->player.gun[active].w_mag_size;
		core->player.gun[active].w_magazine =
			core->player.gun[active].w_mag_size;
	}
	else
	{
		core->player.gun[active].w_magazine =
			core->player.inventory[active].quantity;
		core->player.inventory[active].quantity = 0;
	}
	if (core->player.inventory[active].quantity < 0)
		core->player.inventory[active].quantity = 0;
}

void	reload_gun_norminette(t_core *core, int active)
{
	core->player.inventory[active].quantity -=
		(core->player.gun[active].w_mag_size -
		core->player.gun[active].w_magazine);
	core->player.gun[active].w_magazine =
	core->player.gun[active].w_mag_size;
}

void	reload_gun(t_core *core)
{
	int	active;

	active = core->player.active_wp;
	if (core->player.gun[active].w_status != 3 &&
			core->player.inventory[active].quantity > 0)
	{
		core->player.gun[core->player.active_wp].w_status = 3;
		if (core->player.gun[active].w_magazine > 0)
		{
			if (core->player.gun[active].w_mag_size -
				core->player.gun[active].w_magazine <=
				core->player.inventory[active].quantity)
				reload_gun_norminette(core, active);
			else
			{
				core->player.gun[active].w_magazine +=
					core->player.inventory[active].quantity;
				core->player.inventory[active].quantity = 0;
			}
		}
		else
			reload_gun2(core, active);
	}
}
