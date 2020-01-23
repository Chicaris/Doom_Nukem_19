/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:03:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 11:06:42 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		move_fall(t_core *core)
{
	core->camera.speed[0] -= FXY * core->camera.speed[0] * DELTA_T;
	core->camera.speed[1] -= FXY * core->camera.speed[1] * DELTA_T;
	core->camera.speed[2] -= GRAVITY * DELTA_T;
}

void		move_floor(t_core *core, float underflow[3])
{
	get_vector(core->camera.speed, 0.0, 0.0, 0.0);
	get_vector(underflow, 0.0, 0.0,
			core->level.sectors[core->sector_in].floor_height +
			ZMIN - (float)(core->step_status * ZMIN / 2)
			- core->camera.origin[2]);
	update_camera_pos(&core->camera, underflow);
}

void		move(t_core *core)
{
	float		current_pos[3];
	float		underflow[3];
	float		delta_pos[3];

	vector_cpy(delta_pos, core->camera.speed);
	vector_scale(delta_pos, DELTA_T);
	vector_cpy(current_pos, core->camera.origin);
	vector_add(current_pos, delta_pos);
	if (is_inside_maze(core, current_pos) == true
			&& core->debug != DEBUG_FDF_MASK)
	{
		if (check_door(core, current_pos) == true)
		{
			update_camera_pos(&core->camera, delta_pos);
			if (core->camera.origin[2] >
					core->level.sectors[core->sector_in].floor_height
					+ ZMIN - (float)(core->step_status * ZMIN / 2))
				move_fall(core);
			else
				move_floor(core, underflow);
		}
	}
	else
		get_vector(core->camera.speed, 0.0, 0.0, 0.0);
	floor_is_lava(core);
}
