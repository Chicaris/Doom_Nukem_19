/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:30:47 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 12:31:27 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	mouse_motion(t_core *core, SDL_Event event)
{
	t_mouse		*self;
	float		distance;

	self = &core->mouse;
	self->curr[0] = event.motion.x;
	self->curr[1] = event.motion.y;
	if (core->game_status == game)
	{
		distance = -(float)(event.motion.xrel) * M_SENSITIVITY;
		rotate_world_z(&core->camera, distance * M_PI);
		distance = -(float)(event.motion.yrel) * M_SENSITIVITY;
		rotate_camera_right(&core->camera, distance * M_PI);
	}
	if (core->game_status == menu || core->game_status == pause_menu)
	{
		if (event.motion.x >= 260 && event.motion.x < 545)
		{
			if (event.motion.y >= 135 && event.motion.y < 230)
				core->selected = 0;
			if (event.motion.y >= 335 && event.motion.y < 430)
				core->selected = 1;
		}
	}
}
