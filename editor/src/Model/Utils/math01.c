/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:15:58 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 14:15:59 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/editor.h"

float			scalar_product_2(float vect1[2], float vect2[2])
{
	return (vect1[0] * vect2[0] + vect1[1] * vect2[1]);
}

t_bool			invert_matrix(float res[2][2], float m[2][2])
{
	float	det;

	det = (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
	if (fabs(det) < FLT_EPSILON)
		return (false);
	res[0][0] = (1.0 / det) * m[1][1];
	res[0][1] = -(1.0 / det) * m[0][1];
	res[1][0] = -(1.0 / det) * m[1][0];
	res[1][1] = (1.0 / det) * m[0][0];
	return (true);
}

t_bool			line_intersection(float res[2], float line[2][2],
		float pos[2], float dir[2])
{
	float	matrix[2][2];
	float	inv[2][2];
	float	cst[2];

	matrix[0][0] = (line[1][1] - line[0][1]);
	matrix[0][1] = -(line[1][0] - line[0][0]);
	matrix[1][0] = dir[1];
	matrix[1][1] = -dir[0];
	cst[0] = line[1][1] * line[0][0] - line[1][0] * line[0][1];
	cst[1] = dir[1] * pos[0] - dir[0] * pos[1];
	if (invert_matrix(inv, matrix) == true)
	{
		res[0] = (cst[0] * inv[0][0] + cst[1] * inv[0][1]);
		res[1] = (cst[0] * inv[1][0] + cst[1] * inv[1][1]);
		return (true);
	}
	else
		return (false);
}

t_bool			check_intersection(float res[2], t_wall *wall)
{
	float	dir1[2];
	float	dir2[2];

	dir1[0] = res[0] - (float)wall->start[0];
	dir1[1] = res[1] - (float)wall->start[1];
	dir2[0] = res[0] - (float)wall->end[0];
	dir2[1] = res[1] - (float)wall->end[1];
	if (scalar_product_2(dir1, dir2) < 0)
		return (true);
	return (false);
}

t_bool			check_direction(float res[2], float ray_dir[2], float point[2])
{
	float	dir1[2];
	float	dir2[2];

	dir1[0] = point[0] - res[0];
	dir1[1] = point[1] - res[1];
	dir2[0] = ray_dir[0];
	dir2[1] = ray_dir[1];
	if (scalar_product_2(dir1, dir2) < 0)
		return (true);
	return (false);
}
