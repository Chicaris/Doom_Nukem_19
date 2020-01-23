/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:20:07 by hde-moff          #+#    #+#             */
/*   Updated: 2019/10/14 13:54:40 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

static void		draw_horizontal(t_core *core)
{
	int		limit[2][2];
	int		i;

	limit[0][0] = 0;
	limit[0][1] = core->grid->center[1];
	limit[1][0] = MAP_WIDTH;
	limit[1][1] = core->grid->center[1];
	i = core->grid->center[1];
	while (i > 0)
	{
		draw_line(core->sdl.surface, limit[0], limit[1], GREY);
		i -= STEP_GRID;
		limit[0][1] = i;
		limit[1][1] = i;
	}
	i = core->grid->center[1];
	while (i < WIN_HEIGHT)
	{
		i += STEP_GRID;
		limit[0][1] = i;
		limit[1][1] = i;
		draw_line(core->sdl.surface, limit[0], limit[1], GREY);
	}
}

static void		draw_vertical(t_core *core)
{
	int		limit[2][2];
	int		i;

	limit[0][0] = core->grid->center[0];
	limit[0][1] = 0;
	limit[1][0] = core->grid->center[0];
	limit[1][1] = WIN_HEIGHT;
	i = core->grid->center[0];
	while (i > 0)
	{
		draw_line(core->sdl.surface, limit[0], limit[1], GREY);
		i -= STEP_GRID;
		limit[0][0] = i;
		limit[1][0] = i;
	}
	i = core->grid->center[0];
	while (i < WIN_HEIGHT)
	{
		i += STEP_GRID;
		limit[0][0] = i;
		limit[1][0] = i;
		draw_line(core->sdl.surface, limit[0], limit[1], GREY);
	}
}

void			draw_grid(t_core *core)
{
	draw_vertical(core);
	draw_horizontal(core);
}

void			reset_first_click(t_core *core)
{
	core->grid->first_click[0] = -1;
	core->grid->first_click[1] = -1;
	core->grid->tst = 0;
}

t_bool			init_grid(t_core *core)
{
	t_grid	*self;

	if (!(self = (t_grid *)malloc(sizeof(t_grid))))
		return (false);
	self->center[0] = MAP_WIDTH / 2;
	self->center[1] = WIN_HEIGHT / 2;
	self->tst = 0;
	self->first_click[0] = -1;
	self->first_click[1] = -1;
	self->second_click[0] = -1;
	self->second_click[1] = -1;
	core->grid = self;
	return (true);
}
