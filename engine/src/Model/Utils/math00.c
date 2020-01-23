/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:58:13 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 10:06:19 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		float_equality(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

t_bool		invert_matrix(float res[2][2], float m[2][2])
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

float		scalar_product_3(float a[3], float b[3])
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

float		scalar_product_2(float vect1[2], float vect2[2])
{
	return (vect1[0] * vect2[0] + vect1[1] * vect2[1]);
}

float		get_distance_vect(float a[3], float b[3])
{
	return (sqrtf((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1])
				* (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2])));
}
