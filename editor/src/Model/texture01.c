/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:21 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:28:10 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		load_hud_1(t_core *core)
{
	core->textures[10] = SDL_LoadBMP("res/textures/heart.bmp");
	core->textures[11] = SDL_LoadBMP("res/textures/ammoHousing.bmp");
	core->textures[12] = SDL_LoadBMP("res/textures/Picon.bmp");
	core->textures[13] = SDL_LoadBMP("res/textures/Micon.bmp");
	core->textures[14] = SDL_LoadBMP("res/textures/Dicon.bmp");
	core->textures[15] = SDL_LoadBMP("res/textures/key.bmp");
	core->textures[16] = SDL_LoadBMP("res/textures/ammo.bmp");
	core->textures[17] = SDL_LoadBMP("res/textures/Dammo.bmp");
	core->textures[18] = SDL_LoadBMP("res/textures/Pammo.bmp");
	core->textures[19] = SDL_LoadBMP("res/textures/life.bmp");
	core->textures[20] = SDL_LoadBMP("res/textures/rest.bmp");
	core->textures[21] = SDL_LoadBMP("res/textures/fire1.bmp");
	core->textures[22] = SDL_LoadBMP("res/textures/fire2.bmp");
	core->textures[23] = SDL_LoadBMP("res/textures/reload1.bmp");
	core->textures[24] = SDL_LoadBMP("res/textures/reload2.bmp");
	core->textures[25] = SDL_LoadBMP("res/textures/reload3.bmp");
	core->textures[26] = SDL_LoadBMP("res/textures/reload4.bmp");
}

void		load_hud_2(t_core *core)
{
	core->textures[27] = SDL_LoadBMP("res/textures/Drest.bmp");
	core->textures[28] = SDL_LoadBMP("res/textures/Dfire1.bmp");
	core->textures[29] = SDL_LoadBMP("res/textures/Dfire2.bmp");
	core->textures[30] = SDL_LoadBMP("res/textures/Dfire3.bmp");
	core->textures[31] = SDL_LoadBMP("res/textures/Dempty1.bmp");
	core->textures[32] = SDL_LoadBMP("res/textures/Dempty2.bmp");
	core->textures[33] = SDL_LoadBMP("res/textures/Dempty3.bmp");
	core->textures[34] = SDL_LoadBMP("res/textures/Dempty4.bmp");
	core->textures[35] = SDL_LoadBMP("res/textures/Dempty5.bmp");
	core->textures[36] = SDL_LoadBMP("res/textures/Dempty6.bmp");
	core->textures[37] = SDL_LoadBMP("res/textures/Dreload1.bmp");
	core->textures[38] = SDL_LoadBMP("res/textures/Dreload2.bmp");
	core->textures[39] = SDL_LoadBMP("res/textures/Dreload3.bmp");
	core->textures[40] = SDL_LoadBMP("res/textures/Dreload4.bmp");
}

void		load_hud_3(t_core *core)
{
	core->textures[41] = SDL_LoadBMP("res/textures/Dreload5.bmp");
	core->textures[42] = SDL_LoadBMP("res/textures/Dreload6.bmp");
	core->textures[43] = SDL_LoadBMP("res/textures/Dreload7.bmp");
	core->textures[44] = SDL_LoadBMP("res/textures/Dreload8.bmp");
	core->textures[45] = SDL_LoadBMP("res/textures/Dreload9.bmp");
	core->textures[46] = SDL_LoadBMP("res/textures/Prest.bmp");
	core->textures[47] = SDL_LoadBMP("res/textures/Pfire1.bmp");
	core->textures[48] = SDL_LoadBMP("res/textures/Pfire2.bmp");
	core->textures[49] = SDL_LoadBMP("res/textures/Pfire3.bmp");
	core->textures[50] = SDL_LoadBMP("res/textures/Pfire4.bmp");
	core->textures[51] = SDL_LoadBMP("res/textures/Preload1.bmp");
	core->textures[52] = SDL_LoadBMP("res/textures/Preload2.bmp");
	core->textures[53] = SDL_LoadBMP("res/textures/Preload3.bmp");
	core->textures[54] = SDL_LoadBMP("res/textures/Preload3,5.bmp");
	core->textures[55] = SDL_LoadBMP("res/textures/Preload4.bmp");
	core->textures[56] = SDL_LoadBMP("res/textures/Preload5.bmp");
	core->textures[57] = SDL_LoadBMP("res/textures/Preload6.bmp");
	core->textures[58] = SDL_LoadBMP("res/textures/Preload7.bmp");
}

void		load_flag_texture(t_core *core)
{
	core->textures[59] = SDL_LoadBMP("res/textures/flag.bmp");
	core->textures[60] = SDL_LoadBMP("res/textures/viseur.bmp");
	core->textures[61] = SDL_LoadBMP("res/textures/impact.bmp");
	core->textures[62] = SDL_LoadBMP("res/textures/lava.bmp");
	core->textures[63] = SDL_LoadBMP("res/textures/sky.bmp");
}
