/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:17:24 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 11:00:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

void			set_pixel(SDL_Surface *screen, int x, int y, uint32_t color)
{
	if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
		((uint32_t *)screen->pixels)[x + WIN_WIDTH * y] = color;
}

static void		fdf(t_core *core, t_sect_list *world)
{
	float	matrix_transform[4][4];
	int		i;

	i = 0;
	world_to_camera(&core->camera, matrix_transform);
	SDL_FillRect(core->sdl.surface, NULL, 0x000000);
	while (world != NULL)
	{
		if (world->visible == 1)
			draw_sector(core, world, matrix_transform);
		world = world->next;
		i++;
	}
}

void			paint2(t_core *core)
{
	int				thread_id;
	t_raycast_args	raycast_args[THREAD_NUMBER];
	int				x_begin;
	int				n_steps;

	x_begin = 0;
	n_steps = (WIN_WIDTH + THREAD_NUMBER - 1) / THREAD_NUMBER;
	thread_id = -1;
	while (++thread_id < THREAD_NUMBER)
	{
		raycast_args[thread_id].core = core;
		raycast_args[thread_id].x_begin = x_begin;
		raycast_args[thread_id].n_steps = MIN(n_steps, WIN_WIDTH - x_begin);
		pthread_create(&(raycast_args[thread_id].thread), NULL,
				raycast, &raycast_args[thread_id]);
		x_begin += n_steps;
	}
	while (thread_id-- > 0)
		pthread_join(raycast_args[thread_id].thread, NULL);
}

void			paint(t_core *core)
{
	t_sect_list		*world;

	world = core->world;
	core->sector_in = get_sector(core);
	if (core->sector_in != -1)
	{
		if (core->debug == DEBUG_FDF_MASK)
			fdf(core, world);
		else
			paint2(core);
	}
	display_hud(core);
	SDL_UpdateWindowSurface(core->sdl.window);
}
