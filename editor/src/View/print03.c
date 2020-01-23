/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:28:12 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:53:06 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		print_texture_list(t_core *core)
{
	int				i;
	SDL_Surface		*texture;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		printf("TEXTURE %i\n", i);
		texture = core->textures[i];
		print_texture(texture);
		i++;
	}
}

void		print_sector(t_sector *sector)
{
	printf("start_wall :\t\t%i\n", sector->start_wall);
	printf("num_walls :\t\t%i\n", sector->num_walls);
	printf("floor_height :\t\t%f\n", sector->floor_height);
	printf("ceiling_height :\t%f\n", sector->ceiling_height);
	printf("floor_texture :\t\t%i\n", sector->floor_texture);
	printf("ceiling_texture :\t%i\n", sector->ceiling_texture);
	printf("\n");
}

void		print_sector_list(t_sector_lst *sector_list)
{
	int		i;

	i = 0;
	if (sector_list == NULL)
		printf("sector_list == NULL\n");
	while (sector_list != NULL)
	{
		printf("Sector_list number : %i\n", i);
		print_sector(sector_list->sector);
		sector_list = sector_list->next;
		i++;
	}
}

void		print_controller_draw(void)
{
	printf("Press 'q' to undo first_click\n");
	printf("Left click to set a wall\n");
}

void		print_controller_wall(t_core *core)
{
	printf("Right click to select a sector\n");
	printf("Press 'u' to undo the last wall added\n");
	if (core->select->sector >= 0)
	{
		printf("Left click to select a wall in the selected sector\n");
		if (core->select->wall >= 0)
			printf("Press '+' to change next_sector\n");
	}
}
