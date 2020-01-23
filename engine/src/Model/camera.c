/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:36:19 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 19:38:28 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		camera_move(t_core *core, float vect[3])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		core->camera.origin[i] = core->camera.origin[i] + vect[i];
		core->camera.lookat[i] = core->camera.lookat[i] + vect[i];
		i++;
	}
}

void		set_projection(t_core *core, int proj)
{
	core->camera.projection = proj;
}

t_bool		init_camera(t_core *core)
{
	t_camera	camera;

	camera.fov_x = M_PI / 3;
	camera.focal = (WIN_WIDTH / 2) / (tan(camera.fov_x / 2));
	camera.fov_y = 2 * atan((WIN_HEIGHT / 2) / camera.focal);
	vector_cpy(camera.origin, core->level.origin_player);
	vector_scale(camera.origin, STEP);
	get_vector(camera.lookat, 1.0 + camera.origin[0], 1.0 +
		camera.origin[1], 0.0);
	get_vector(camera.up, 0.0, 0.0, -1.0);
	get_vector(camera.speed, 0.0, 0.0, 0.0);
	ft_memcpy(&core->camera, &camera, sizeof(t_camera));
	return (true);
}
