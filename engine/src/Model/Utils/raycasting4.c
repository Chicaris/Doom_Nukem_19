/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:40:35 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 16:13:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		norminette_vect(float dest[23][3], float a[3],
		float b[3], float c[3])
{
	vector_cpy(dest[0], a);
	vector_cpy(dest[1], b);
	vector_cpy(dest[2], c);
}

t_bool		clip_wall(float intersection[3], t_wall *current_wall,
		t_sector *sector)
{
	if (((intersection[0] - (float)current_wall->start[0]) *
				(intersection[0] - (float)current_wall->end[0]) <=
				INTERSECT_TOL)
			&& ((intersection[1] - (float)current_wall->start[1]) *
				(intersection[1] - (float)current_wall->end[1]) <=
				INTERSECT_TOL)
			&& (intersection[2] >= sector->floor_height)
			&& (intersection[2] <= sector->ceiling_height))
		return (true);
	return (false);
}

uint32_t	get_rgb(t_core *core, float offset[3], t_wall *wall,
		SDL_Surface *texture)
{
	uint32_t	rgb_tmp;
	t_flag		*flag;
	float		offset_tmp[3];

	flag = wall->flag;
	if (flag != NULL)
	{
		if ((offset[0] >= flag->top[0] && offset[0] <
					flag->top[0] + flag->width)
				&& (offset[1] >= flag->top[1] && offset[1] <
					flag->top[1] + flag->heigth))
		{
			offset_tmp[0] = offset[0] - flag->top[0];
			offset_tmp[1] = offset[1] - flag->top[1];
			rgb_tmp = get_pixel(core->level.textures[flag->texture],
					offset_tmp[0], offset_tmp[1]);
			if ((rgb_tmp & AMASK) != 0)
				return (rgb_tmp);
		}
	}
	return (get_pixel(texture, offset[0], offset[1]));
}

uint32_t	get_pixel_door(SDL_Surface *surface, float offset[2],
		float width, float height)
{
	int		x;
	int		y;
	uint8_t	*p;

	x = (int)(offset[0] / width) * surface->w;
	y = (int)(offset[1] / height) * surface->h;
	p = (uint8_t *)surface->pixels + y * surface->pitch
		+ x * surface->format->BytesPerPixel;
	return (*(uint32_t *)p);
}

uint32_t	get_door_rgb(t_core *core, t_wall *wall,
		float intersection[3], t_sector *sector)
{
	uint32_t	rgb;
	t_sector	*sector_next;
	float		height[3];
	float		texture_offset[2];

	get_texture_offset(wall, intersection, texture_offset,
			sector);
	sector_next = &core->level.sectors[wall->next_sector];
	height[0] = sector_next->ceiling_height;
	height[2] = fabs(height[0] - sector_next->floor_height);
	height[1] = sector_next->ceiling_height - height[2] * core->step_door;
	if (intersection[2] < height[0] && intersection[2] > height[1])
	{
		rgb = get_rgb(core, texture_offset, wall,
				core->level.textures[wall->m_texture]);
		if ((rgb & RMASK) != 0)
			return (rgb);
		else
			return (RED);
	}
	else
		rgb = RED;
	return (rgb);
}
