/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:05:20 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 14:05:21 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		camera_step(t_camera *camera, float step_size)
{
	float		step[3];

	vector_diff(step, camera->origin, camera->lookat);
	step[2] = 0.0;
	vector_normalize(step);
	vector_scale(step, step_size);
	camera->speed[0] += step[0];
	camera->speed[1] += step[1];
}

void		straff_key(t_camera *camera, float step_size)
{
	float	to_axe[3];
	float	right_axe[3];

	vector_diff(to_axe, camera->origin, camera->lookat);
	vector_normalize(to_axe);
	vector_cross(right_axe, to_axe, camera->up);
	right_axe[2] = 0.0;
	vector_normalize(right_axe);
	vector_scale(right_axe, step_size);
	camera->speed[0] += right_axe[0];
	camera->speed[1] += right_axe[1];
}

void		up_key(t_core *core, int step)
{
	float		to_axe[3];
	float		test[3];

	vector_init(to_axe, 0.0, 0.0, 1.0);
	vector_scale(to_axe, step);
	if (core->fly_mode == 1)
	{
		vector_cpy(test, core->camera.origin);
		vector_add(test, to_axe);
		if (is_inside_maze(core, test) == true)
		{
			vector_add(core->camera.origin, to_axe);
			vector_add(core->camera.lookat, to_axe);
		}
	}
	else
	{
		vector_add(core->camera.origin, to_axe);
		vector_add(core->camera.lookat, to_axe);
	}
}

void		update_camera_pos(t_camera *camera, float offset[3])
{
	vector_add(camera->origin, offset);
	vector_add(camera->lookat, offset);
}
