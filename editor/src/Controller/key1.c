/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:44:48 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:44:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		move(t_core *core, SDL_KeyboardEvent key)
{
	int		step[2];

	step[0] = 0;
	step[1] = 0;
	if (key.keysym.sym == SDLK_LEFT)
	{
		step[0] = STEP_MOVE;
		move_center(core, step);
	}
	if (key.keysym.sym == SDLK_RIGHT)
	{
		step[0] = -STEP_MOVE;
		move_center(core, step);
	}
	if (key.keysym.sym == SDLK_UP)
	{
		step[1] = STEP_MOVE;
		move_center(core, step);
	}
	if (key.keysym.sym == SDLK_DOWN)
	{
		step[1] = -STEP_MOVE;
		move_center(core, step);
	}
}
