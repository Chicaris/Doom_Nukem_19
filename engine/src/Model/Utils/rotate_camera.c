/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:21:10 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 10:22:02 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		update_camera(t_camera *self, float matrix[4][4])
{
	float to[3];

	vector_cpy(self->lookat, self->origin);
	vector_init(to, matrix[0][2], matrix[1][2], matrix[2][2]);
	vector_add(self->lookat, to);
	vector_init(self->up, matrix[0][0], matrix[1][0], matrix[2][0]);
}

void		rotate_world_z(t_camera *self, float theta)
{
	float	frot_matrix[4][4];
	float	fcam_matrix[4][4];
	float	final_matrix[4][4];

	get_rotate_z(frot_matrix, theta);
	camera_to_world(self, fcam_matrix);
	fcam_matrix[3][0] = 0.0;
	fcam_matrix[3][1] = 0.0;
	fcam_matrix[3][2] = 0.0;
	matrix_multi(final_matrix, frot_matrix, fcam_matrix);
	update_camera(self, final_matrix);
}

void		rotate_camera_right(t_camera *self, float theta)
{
	float	rot_matrix[4][4];
	float	fcam_matrix[4][4];
	float	final_matrix[4][4];

	get_rotate_y(rot_matrix, theta);
	camera_to_world(self, fcam_matrix);
	matrix_multi(final_matrix, fcam_matrix, rot_matrix);
	update_camera(self, final_matrix);
}

void		move_camera(t_camera *self, float distance)
{
	float		move_vector[3];

	vector_diff(move_vector, self->origin, self->lookat);
	vector_normalize(move_vector);
	vector_scale(move_vector, distance);
	vector_add(self->origin, move_vector);
	vector_add(self->lookat, move_vector);
}
