/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:04:24 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 10:20:33 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		matrix_translation(float dst[4][4], float vec[3])
{
	matrix_unit(dst);
	dst[0][3] = vec[0];
	dst[1][3] = vec[1];
	dst[2][3] = vec[2];
}

void		rotation_init(t_camera *camera, float up_axe[3],
		float to_axe[3], float right_axe[3])
{
	vector_diff(to_axe, camera->origin, camera->lookat);
	vector_normalize(to_axe);
	vector_cross(right_axe, to_axe, camera->up);
	vector_normalize(right_axe);
	vector_cross(up_axe, right_axe, to_axe);
	vector_normalize(up_axe);
}

void		matrix_rotation(float dst[4][4], t_camera *camera)
{
	int			i;
	int			j;
	float		up_axe[3];
	float		to_axe[3];
	float		right_axe[3];

	rotation_init(camera, up_axe, to_axe, right_axe);
	matrix_unit(dst);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (j == 0)
				dst[i][j] = up_axe[i];
			else if (j == 1)
				dst[i][j] = right_axe[i];
			else
				dst[i][j] = to_axe[i];
			j++;
		}
		i++;
	}
}

void		camera_to_world(t_camera *self, float matrix[4][4])
{
	float		matrix_rot[4][4];
	float		matrix_trans[4][4];

	matrix_rotation(matrix_rot, self);
	matrix_translation(matrix_trans, self->origin);
	matrix_multi(matrix, matrix_trans, matrix_rot);
}

void		world_to_camera(t_camera *self, float matrix[4][4])
{
	float		matrix_tmp[4][4];
	float		matrix_rot[4][4];
	float		matrix_trans[4][4];
	float		vec_trans[3];

	matrix_rotation(matrix_tmp, self);
	matrix_transpose(matrix_rot, matrix_tmp);
	vector_cpy(vec_trans, self->origin);
	vector_scale(vec_trans, -1.0);
	matrix_translation(matrix_trans, vec_trans);
	matrix_multi(matrix, matrix_rot, matrix_trans);
}
