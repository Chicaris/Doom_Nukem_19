/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:11:58 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 13:12:00 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void				draw_circle(SDL_Surface *screen,
		int p1[2], int p2[2], uint32_t color)
{
	mset_pixel(screen, p1[0] + p2[0], p1[1] + p2[1], color);
	mset_pixel(screen, p1[0] - p2[0], p1[1] + p2[1], color);
	mset_pixel(screen, p1[0] + p2[0], p1[1] - p2[1], color);
	mset_pixel(screen, p1[0] - p2[0], p1[1] - p2[1], color);
	mset_pixel(screen, p1[0] + p2[1], p1[1] + p2[0], color);
	mset_pixel(screen, p1[0] - p2[1], p1[1] + p2[0], color);
	mset_pixel(screen, p1[0] + p2[1], p1[1] - p2[0], color);
	mset_pixel(screen, p1[0] - p2[1], p1[1] - p2[0], color);
}

void				draw_circle_bres(SDL_Surface *screen,
		int center[2], int r, uint32_t color)
{
	int point[2];
	int d;

	d = 3 - 2 * r;
	point[0] = 0;
	point[1] = r;
	draw_circle(screen, center, point, color);
	while (point[1] >= point[0])
	{
		point[0] += 1;
		if (d > 0)
		{
			point[1] -= 1;
			d = d + 4 * (point[0] - point[1]) + 10;
		}
		else
			d = d + 4 * point[0] + 6;
		draw_circle(screen, center, point, color);
	}
}

static void			init_draw(int point[4], int delta[4], int p1[2], int p2[2])
{
	point[0] = p1[0];
	point[2] = p1[1];
	point[1] = p2[0];
	point[3] = p2[1];
	delta[0] = point[0] < point[1] ? 1 : -1;
	delta[1] = point[2] < point[3] ? 1 : -1;
	delta[2] = abs(point[1] - point[0]);
	delta[3] = abs(point[3] - point[2]);
}

void				draw_line(SDL_Surface *screen,
		int p1[2], int p2[2], uint32_t color)
{
	int		point[4];
	int		delta[4];
	int		err;
	int		e2;

	init_draw(point, delta, p1, p2);
	err = (delta[2] > delta[3] ? delta[2] : -delta[3]) / 2;
	while (1)
	{
		mset_pixel(screen, point[0], point[2], color);
		if (point[0] == point[1] && point[2] == point[3])
			break ;
		e2 = err;
		if (e2 > -delta[2])
		{
			err -= delta[3];
			point[0] += delta[0];
		}
		if (e2 < delta[3])
		{
			err += delta[2];
			point[2] += delta[1];
		}
	}
}

void				draw_wall(t_core *core, t_wall *wall, uint32_t color)
{
	int		p1[2];
	int		p2[2];

	p1[0] = (wall->start[0] * STEP_GRID) + core->grid->center[0];
	p1[1] = (wall->start[1] * STEP_GRID) + core->grid->center[1];
	p2[0] = (wall->end[0] * STEP_GRID) + core->grid->center[0];
	p2[1] = (wall->end[1] * STEP_GRID) + core->grid->center[1];
	draw_line(core->sdl.surface, p1, p2, color);
}
