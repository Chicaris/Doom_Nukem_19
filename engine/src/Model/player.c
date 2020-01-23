/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:59:33 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/14 10:36:14 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	update_life(t_core *core, int step)
{
	if (core->player.life + step >= 0 && core->player.life + step < 12)
		core->player.life += step;
	if (core->player.life == 0)
		core->game_status = game_over;
}

void	update_player(t_core *core, int item_id)
{
	if (item_id == 0)
	{
		if (core->player.life < 11)
			core->player.life++;
	}
	else if (item_id == 1)
		core->player.inventory[3].quantity = 1;
	else if (item_id == 2)
		core->player.gun[0].posessed = 1;
	else if (item_id == 3)
		core->player.gun[1].posessed = 1;
	else if (item_id == 4)
		core->player.gun[2].posessed = 1;
	else if (item_id == 5)
		core->player.inventory[0].quantity += 30;
	else if (item_id == 6)
		core->player.inventory[1].quantity += 30;
	else if (item_id == 7)
		core->player.inventory[2].quantity += 30;
}

t_bool	init_items(t_core *core)
{
	t_item_ls	item_hand;
	int			i;

	i = 0;
	if (!(item_hand.item_list = (t_item *)malloc(sizeof(t_item) * ITEM_NBR)))
		return (false);
	item_hand.item_list[0].item_name = "Life";
	item_hand.item_list[1].item_name = "Sacred Key";
	item_hand.item_list[2].item_name = "Rifle";
	item_hand.item_list[3].item_name = "Demon Gun ";
	item_hand.item_list[4].item_name = "Pistol";
	item_hand.item_list[5].item_name = "Rifle ammo";
	item_hand.item_list[6].item_name = "Demon Gun ammo";
	item_hand.item_list[7].item_name = "Pistol ammo";
	while (i++ < ITEM_NBR)
	{
		item_hand.item_list[i].item_id = i;
		item_hand.item_list[i].quantity = 1;
	}
	ft_memcpy(&core->item_ls, &item_hand, sizeof(t_item_ls));
	return (true);
}

t_bool	pick_up_item(t_core *core, int item_id)
{
	SDL_Rect	winpos;
	SDL_Surface	*texte;
	SDL_Color	color;

	winpos.x = 250;
	winpos.y = 10;
	color = int_to_rgb(RED);
	if (item_id >= 0 && item_id < ITEM_NBR)
	{
		update_player(core, item_id);
		texte = get_texte(core->item_ls.item_list[item_id].item_name,
			"Special.ttf", color, 32);
		SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
		SDL_UpdateWindowSurface(core->sdl.window);
	}
	return (true);
}

void	change_weapon(t_core *core, int modif)
{
	core->player.gun[core->player.active_wp].w_fire_spr = 0;
	core->player.active_wp += modif;
	if (core->player.active_wp < 0)
		core->player.active_wp = 2;
	if (core->player.active_wp > 2)
		core->player.active_wp = 0;
}
