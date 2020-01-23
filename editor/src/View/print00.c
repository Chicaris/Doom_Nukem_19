/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:27:59 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:49:32 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		print_controller_sector(t_core *core)
{
	ft_putstr("Left click to select a sector\n");
	if (core->select->sector >= 0)
	{
		ft_putstr("Press '7' or '8' to change the ceil height\n");
		ft_putstr("Press '4' or '5' to change the floor height\n");
	}
}

void		print_controller_monster(void)
{
	ft_putstr("Left click to place a monster\n");
	ft_putstr("Right click to select a monster\n");
	ft_putstr("Press 'u' to undo the last monster added\n");
}

void		print_controller_flag(t_core *core)
{
	ft_putstr("Right click to select a sector\n");
	if (core->select->sector >= 0)
	{
		ft_putstr("Left click to select a wall in the selected sector\n");
		if (core->select->wall >= 0)
			ft_putstr("Press 'x' to add a flag on the selected wall\n");
	}
}

void		print_controller(t_core *core)
{
	ft_putstr("\e[1;1H\e[2J");
	ft_putstr("Arrow:\t\tmove\n");
	ft_putstr("d:		draw mode\n");
	ft_putstr("w:		wall mode\n");
	ft_putstr("e:		sector mode\n");
	ft_putstr("f:		flag mode\n");
	ft_putstr("m:		monster mode\n");
	ft_putstr("s:		save\n");
	ft_putstr("\n\n");
	if (core->option == draw)
		print_controller_draw(core);
	if (core->option == wall_select)
		print_controller_wall(core);
	if (core->option == sector_select)
		print_controller_draw(core);
	if (core->option == player)
		ft_putstr("Left click to place the player\n");
	if (core->option == monster_mode)
		print_controller_monster();
	if (core->option == flag_mode)
		print_controller_flag(core);
}
