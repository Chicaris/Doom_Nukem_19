/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:15:18 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:25:49 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

int				count_textures(void)
{
	int				file_count;
	DIR				*dirp;
	struct dirent	*entry;

	file_count = 0;
	dirp = opendir("./res/textures");
	while ((entry = readdir(dirp)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			file_count++;
		}
	}
	closedir(dirp);
	file_count--;
	return (file_count);
}

void			load_wall_texture(t_core *core)
{
	core->textures[0] = SDL_LoadBMP("res/textures/volet.bmp");
	core->textures[1] = SDL_LoadBMP("res/textures/kstone2.bmp");
	core->textures[2] = SDL_LoadBMP("res/textures/mbrk2_1.bmp");
	core->textures[3] = SDL_LoadBMP("res/textures/pvsepblu.bmp");
	core->textures[4] = SDL_LoadBMP("res/textures/shelf_2.bmp");
	core->textures[5] = SDL_LoadBMP("res/textures/wdriv1.bmp");
	core->textures[6] = SDL_LoadBMP("res/textures/marble_tile.bmp");
	core->textures[7] = SDL_LoadBMP("res/textures/menu.bmp");
}

void			load_monster_texture(t_core *core)
{
	core->textures[8] = SDL_LoadBMP("res/textures/monster01.bmp");
	core->textures[9] = SDL_LoadBMP("res/textures/monster02.bmp");
}

t_bool			check_load_textures(t_core *core)
{
	int			i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (core->textures[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

t_bool			load_textures(t_core *core)
{
	load_wall_texture(core);
	load_monster_texture(core);
	load_hud_1(core);
	load_hud_2(core);
	load_hud_3(core);
	load_flag_texture(core);
	return (check_load_textures(core));
}
