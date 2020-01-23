/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:21:40 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/24 13:18:41 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

uint32_t		get_pixel(SDL_Surface *surface, float i, float j)
{
	int		x;
	int		y;
	uint8_t *p;

	x = (int)i % surface->w;
	y = (int)j % surface->h;
	p = (uint8_t *)surface->pixels + y * surface->pitch
		+ x * surface->format->BytesPerPixel;
	return (*(Uint32 *)p);
}

void			draw_texture(t_core *core, SDL_Surface *texture, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < texture->w && i < 150)
	{
		j = 0;
		while (j < texture->h && j < 150)
		{
			set_pixel(core->sdl.surface, x + i, y + j,
					get_pixel(texture, i, j));
			j++;
		}
		i++;
	}
}

void			draw_objet(t_core *core)
{
	int				i;
	t_pickup_lst	*curr;
	int				point[2];

	i = 0;
	curr = core->pickup_list;
	while (curr != NULL)
	{
		point[0] = curr->pickup->center[0] * STEP_GRID + core->grid->center[0];
		point[1] = curr->pickup->center[1] * STEP_GRID + core->grid->center[1];
		if (i != core->select->pickup)
			draw_circle_bres(core->sdl.surface, point, 3, RED);
		else
			draw_circle_bres(core->sdl.surface, point, 3, YELLOW);
		curr = curr->next;
		i++;
	}
}
