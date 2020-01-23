/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:28:08 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 13:28:10 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		print_player(t_player *player)
{
	printf("position :\t\t(%f %f %f)\n",
			player->position[0], player->position[1], player->position[2]);
	printf("\n");
}

void		print_select(t_select *select)
{
	printf("wall :\t\t\t%i\n", select->wall);
	printf("sector :\t\t\t%i\n", select->sector);
	printf("\n");
}

void		print_wall(t_wall *wall)
{
	printf("start :\t\t(%i %i)\n", wall->start[0], wall->start[1]);
	printf("end :\t\t(%i %i)\n", wall->end[0], wall->end[1]);
	printf("next_sector :\t\t%i\n", wall->next_sector);
	printf("b_texture :\t\t%i\n", wall->b_texture);
	printf("m_texture :\t\t%i\n", wall->m_texture);
	printf("t_texture :\t\t%i\n", wall->t_texture);
	print_flag(wall->flag);
	printf("\n");
}

void		print_wall_list(t_wall_lst *wall_list)
{
	int		i;

	i = 0;
	if (wall_list == NULL)
		printf("wall_list == NULL\n");
	while (wall_list != NULL)
	{
		printf("Wall_list number : %i\n", i);
		print_wall(wall_list->wall);
		wall_list = wall_list->next;
		i++;
	}
}

void		print_texture(SDL_Surface *texture)
{
	printf("width:\t\t%i\n", texture->w);
	printf("height:\t\t%i\n", texture->h);
	printf("pitch:\t\t%i\n", texture->pitch);
	printf("BitsPerPixel:\t\t%i\n", texture->format->BitsPerPixel);
	printf("Rmask:\t\t%i\n", texture->format->Rmask);
	printf("Gmask:\t\t%i\n", texture->format->Gmask);
	printf("Bmask:\t\t%i\n", texture->format->Bmask);
	printf("Amask:\t\t%i\n", texture->format->Amask);
	printf("\n\n");
}
