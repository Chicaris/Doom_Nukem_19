/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:12:03 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 13:12:05 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				mset_pixel(SDL_Surface *screen,
		int x, int y, uint32_t color)
{
	if (x < MAP_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
		((uint32_t *)screen->pixels)[x + WIN_WIDTH * y] = color;
}

void				set_pixel(SDL_Surface *screen, int x, int y, uint32_t color)
{
	if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
		((uint32_t *)screen->pixels)[x + WIN_WIDTH * y] = color;
}

void				draw_map_border(SDL_Surface *screen,
		unsigned width, uint32_t color)
{
	unsigned	i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		set_pixel(screen, width, i, color);
		i++;
	}
}

void				draw_wall_list(t_core *core)
{
	t_wall_lst	*current;
	int			start;

	start = get_start_wall(core);
	current = core->wall_list;
	while (current != NULL)
	{
		if (start > 0)
		{
			start--;
			draw_wall(core, current->wall, WHITE);
		}
		else
			draw_wall(core, current->wall, YELLOW);
		current = current->next;
	}
}
