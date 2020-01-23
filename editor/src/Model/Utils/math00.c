/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:01:33 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 12:51:34 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/editor.h"

t_bool			float_equality(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

t_bool			is_point_equal(int p1[2], int p2[2])
{
	if (p1[0] == p2[0] && p1[1] == p2[1])
		return (true);
	return (false);
}

t_bool			get_coef_droite(float *d, float *k, int a[2], int b[2])
{
	if (float_equality((b[0] - a[0]), 0.0) != true)
	{
		*d = ((float)(b[1] - a[1]) / (float)(b[0] - a[0]));
		*k = a[1] - (*d) * a[0];
		return (true);
	}
	return (false);
}

float			dist_point_droite(float point[2], t_wall *wall)
{
	float	dist;
	float	d;
	float	k;

	if (get_coef_droite(&d, &k, wall->start, wall->end) != true)
		dist = fabs(point[0] - wall->start[0]);
	else
		dist = fabs((d * point[0]) + k - point[1]) / (sqrtf(1.0 + (d * d)));
	return (dist);
}

t_bool			clip_wall(float point[2], t_wall *wall)
{
	if (((point[0] - (float)wall->start[0]) *
				(point[0] - (float)wall->end[0]) <= INTERSECT_TOL)
			&& ((point[1] - (float)wall->start[1]) *
				(point[1] - (float)wall->end[1]) <= INTERSECT_TOL))
		return (true);
	return (false);
}
