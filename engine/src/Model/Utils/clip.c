/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:44 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 09:44:08 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

static int		get_clip_code(float point[3], t_sdl sdl)
{
	int code;

	code = 0;
	if (point[1] > sdl.x_max)
		code |= CLIP_RIGHT;
	if (point[1] < sdl.x_min)
		code |= CLIP_LEFT;
	if (point[0] > sdl.y_max)
		code |= CLIP_UP;
	if (point[0] < sdl.y_min)
		code |= CLIP_DOWN;
	return (code);
}

static void		clip2(t_line *line, t_sdl sdl, int clip_code[2])
{
	int		out_idx;
	float	*pin;
	float	*pout;

	out_idx = (clip_code[0] != CLIP_CENTER) ? 0 : 1;
	pout = line->vect[out_idx];
	pin = line->vect[1 - out_idx];
	if ((clip_code[out_idx] & CLIP_RIGHT) != 0)
	{
		pout[0] = pin[0] + (pout[0] - pin[0]) / (pout[1] - pin[1])
			* ((float)sdl.x_max - pin[1]);
		pout[1] = sdl.x_max;
	}
	if ((clip_code[out_idx] & CLIP_LEFT) != 0)
	{
		pout[0] = pin[0] + (pout[0] - pin[0]) / (pout[1] - pin[1])
			* ((float)sdl.x_min - pin[1]);
		pout[1] = sdl.x_min;
	}
}

static void		clip(t_line *line, t_sdl sdl, int clip_code[2])
{
	int		out_idx;
	float	*pin;
	float	*pout;

	out_idx = (clip_code[0] != CLIP_CENTER) ? 0 : 1;
	pout = line->vect[out_idx];
	pin = line->vect[1 - out_idx];
	if ((clip_code[out_idx] & CLIP_UP) != 0)
	{
		pout[1] = pin[1] + (pout[1] - pin[1]) / (pout[0] - pin[0])
			* ((float)sdl.y_max - pin[0]);
		pout[0] = sdl.y_max;
	}
	if ((clip_code[out_idx] & CLIP_DOWN) != 0)
	{
		pout[1] = pin[1] + (pout[1] - pin[1]) / (pout[0] - pin[0])
			* ((float)sdl.y_min - pin[0]);
		pout[0] = sdl.y_min;
	}
	clip2(line, sdl, clip_code);
}

void			line_clip(t_core *core, t_line *line)
{
	int		clip_code[2];
	int		i;

	while (1)
	{
		i = 0;
		while (i < 2)
		{
			clip_code[i] = get_clip_code(line->vect[i], core->sdl);
			i++;
		}
		if ((clip_code[0] & clip_code[1]) != CLIP_CENTER)
		{
			line->visible = 0;
			break ;
		}
		clip(line, core->sdl, clip_code);
		if ((clip_code[0] | clip_code[1]) == CLIP_CENTER)
			break ;
	}
}
