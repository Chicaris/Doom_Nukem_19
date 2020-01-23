/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:59:49 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/08 15:56:49 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	reload_animation(t_core *core, int active, SDL_Rect winpos)
{
	SDL_BlitSurface(core->level.textures[core->player.gun[active].rload_sprs +
			(core->player.gun[core->player.active_wp].w_reload_spr /
			core->player.gun[core->player.active_wp].w_rload_spd)],
			NULL, core->sdl.surface, &winpos);
	core->player.gun[core->player.active_wp].w_reload_spr++;
	if (core->player.gun[core->player.active_wp].w_reload_spr >
			(core->player.gun[core->player.active_wp].w_rload_spd *
			core->player.gun[active].rload_spr_nbr) - 1)
	{
		core->player.gun[core->player.active_wp].w_reload_spr = 0;
		core->player.gun[core->player.active_wp].w_status = 0;
	}
}

void	empty_animation(t_core *core, int active, SDL_Rect winpos)
{
	SDL_BlitSurface(core->level.textures[core->player.gun[active].empty_sprs +
			(core->player.gun[core->player.active_wp].w_empty_spr / 2)],
			NULL, core->sdl.surface, &winpos);
	if (active == 1)
		core->player.gun[core->player.active_wp].w_empty_spr++;
	if (core->player.gun[core->player.active_wp].w_empty_spr >
		(2 * core->player.gun[active].empty_spr_nbr) - 1)
	{
		core->player.gun[core->player.active_wp].w_empty_spr = 0;
		core->player.gun[core->player.active_wp].w_status = 0;
	}
}

void	fire_animation(t_core *core, int active, SDL_Rect winpos)
{
	SDL_BlitSurface(core->level.textures[core->player.gun[active].fire_sprs +
			(core->player.gun[core->player.active_wp].w_fire_spr /
			core->player.gun[core->player.active_wp].w_rof)],
			NULL, core->sdl.surface, &winpos);
	core->player.gun[core->player.active_wp].w_fire_spr++;
	if (core->player.gun[core->player.active_wp].w_fire_spr >
		(core->player.gun[core->player.active_wp].w_rof *
		core->player.gun[active].fire_spr_nbr) - 1)
	{
		core->player.gun[core->player.active_wp].w_magazine--;
		core->player.gun[core->player.active_wp].w_fire_spr = 0;
		core->player.gun[core->player.active_wp].w_status = 0;
		if (core->player.gun[core->player.active_wp].w_magazine < 1)
			core->player.gun[core->player.active_wp].w_status = 2;
	}
}

void	display_gun(t_core *core, int active)
{
	int			i;
	SDL_Rect	winpos;

	i = 0;
	winpos.x = 300;
	winpos.y = 500;
	if (active == 1)
	{
		winpos.x = 250;
		winpos.y = 440;
	}
	if (core->player.gun[core->player.active_wp].w_status == 0)
		SDL_BlitSurface(core->level.textures[core->player.gun[active].
				rest_sprs], NULL, core->sdl.surface, &winpos);
	else if (core->player.gun[core->player.active_wp].w_status == 1)
		fire_animation(core, active, winpos);
	else if (core->player.gun[core->player.active_wp].w_status == 2)
		empty_animation(core, active, winpos);
	else if (core->player.gun[core->player.active_wp].w_status == 3)
		reload_animation(core, active, winpos);
	display_ammo(core, core->player.active_wp);
}

void	display_ammo(t_core *core, int active)
{
	int			i;
	SDL_Rect	winpos;
	SDL_Surface	*texte;
	SDL_Color	color;

	color = int_to_rgb(WHITE);
	winpos.x = 790;
	winpos.y = 550;
	winpos.h = 50;
	winpos.w = 5;
	i = 0;
	while (i++ < core->player.gun[core->player.active_wp].w_magazine)
	{
		SDL_FillRect(core->sdl.surface, &winpos, 0xa68d4e);
		winpos.x -= 10;
	}
	winpos.x = 690;
	winpos.y = 490;
	SDL_BlitSurface(core->level.textures[11], NULL, core->sdl.surface, &winpos);
	winpos.x = 710;
	winpos.y = 510;
	texte = get_texte(ft_itoa(core->player.inventory[active].quantity),
		core->level.ttf_path[0], color, 16);
	SDL_BlitSurface(texte, NULL, core->sdl.surface, &winpos);
	SDL_FreeSurface(texte);
}
