/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:11:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 16:39:51 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static void		init_draw(int point[4], int delta[4], t_line *line)
{
	point[0] = line->vect[0][1];
	point[1] = line->vect[1][1];
	point[2] = line->vect[0][0];
	point[3] = line->vect[1][0];
	delta[0] = point[0] < point[1] ? 1 : -1;
	delta[1] = point[2] < point[3] ? 1 : -1;
	delta[2] = abs(point[1] - point[0]);
	delta[3] = abs(point[3] - point[2]);
}

void			draw(t_core *core, t_line *line, int color)
{
	int point[4];
	int delta[4];
	int err;
	int e2;

	init_draw(point, delta, line);
	err = (delta[2] > delta[3] ? delta[2] : -delta[3]) / 2;
	while (1)
	{
		set_pixel(core->sdl.surface, core->sdl.x_center + point[0],
				core->sdl.y_center - point[2], color);
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

void			draw_line(t_core *core, t_line *line, float matrix[4][4])
{
	t_line camera_line;

	vector_transform(camera_line.vect[0], matrix, line->vect[0]);
	vector_transform(camera_line.vect[1], matrix, line->vect[1]);
	line_projection(core, &camera_line);
	line_clip(core, &camera_line);
	if (camera_line.visible == 1)
		draw(core, &camera_line, 0x01FE12);
}

void			draw_wall(t_core *core, t_wall_list *wall, float matrix[4][4])
{
	t_line	*line;

	line = wall->lines;
	while (line)
	{
		if (line->visible == 1)
			draw_line(core, line, matrix);
		line = line->next;
	}
}

void			draw_sector(t_core *core, t_sect_list *sector,
		float matrix[4][4])
{
	t_wall_list	*wall;

	wall = sector->wall_list;
	while (wall != NULL)
	{
		if (wall->visible == 1)
			draw_wall(core, wall, matrix);
		wall = wall->next;
	}
}
