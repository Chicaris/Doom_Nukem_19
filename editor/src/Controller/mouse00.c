/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:22:28 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 13:57:26 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool			is_click_sector(t_core *core, float x, float y)
{
	t_sector_lst	*current;
	float			point[2];

	current = core->sector_list;
	point[0] = x;
	point[1] = y;
	while (current != NULL)
	{
		if (is_in_sector(core, current->sector, point) == true)
			return (true);
		current = current->next;
	}
	return (false);
}

void			vector_init_2(int vect[2], int a, int b)
{
	vect[0] = a;
	vect[1] = b;
}

void			vector_cpy_2(int vect1[2], int vect2[2])
{
	vect1[0] = vect2[0];
	vect1[1] = vect2[1];
}

void			draw_option(t_core *core, float x, float y)
{
	t_wall		wall;

	if (core->option == draw)
	{
		if (is_click_sector(core, x, y) == false)
		{
			if (core->grid->tst == 0)
			{
				vector_init_2(core->grid->first_click, round(x), round(y));
				core->grid->tst = 1;
			}
			else
			{
				core->grid->second_click[0] = round(x);
				core->grid->second_click[1] = round(y);
				wall = (t_wall) {{core->grid->first_click[0],
					core->grid->first_click[1]},
					{core->grid->second_click[0], core->grid->second_click[1]},
					-1, 1, 1, 1, NULL};
				add_wall(core, &wall);
				is_new_sector(core);
				vector_cpy_2(core->grid->first_click, core->grid->second_click);
			}
		}
	}
}

void			mouse_button(t_core *core, SDL_MouseButtonEvent event)
{
	float		x;
	float		y;

	x = (float)(event.x - core->grid->center[0]) / STEP_GRID;
	y = (float)(event.y - core->grid->center[1]) / STEP_GRID;
	if (event.button == SDL_BUTTON_LEFT)
	{
		if (event.x >= 0 && event.x <= MAP_WIDTH && event.y >= 0 &&
				event.y <= WIN_HEIGHT)
			in_map(core, x, y);
		else
		{
			is_wall_option(core, event);
			is_sector_option(core, event);
			is_monster_option(core, event);
			is_pickup_option(core, event);
		}
	}
	if (event.button == SDL_BUTTON_RIGHT)
	{
		if (event.x >= 0 && event.x <= MAP_WIDTH && event.y >= 0 &&
				event.y <= WIN_HEIGHT)
			is_right_button(core, x, y);
	}
	paint(core);
}
