/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:08:47 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 11:03:50 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		line_intersection(float res[2], float line[2][2],
		float pos[3], float dir[3])
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

t_bool		get_lambda(float *lambda, float ray_origin[3], float ray_dir[3],
		t_wall *wall)
{
	float	div;
	float	normal[3];
	float	d;

	normal[0] = (float)(wall->end[1] - wall->start[1]);
	normal[1] = (float)(wall->start[0] - wall->end[0]);
	normal[2] = 0.0;
	d = normal[0] * wall->start[0] + normal[1] * wall->start[1];
	div = scalar_product_3(ray_dir, normal);
	if (float_equality(div, 0.0) == false)
	{
		*lambda = (d - scalar_product_3(ray_origin, normal)) / div;
		if (*lambda > 0.0)
			return (true);
	}
	return (false);
}

t_bool		get_lambda_monster(float *lambda, float ray_origin[3],
		float ray_dir[3], t_monster *monster)
{
	float	div;
	float	normal[3];
	float	d;

	normal[0] = (float)(monster->end[1] - monster->start[1]);
	normal[1] = (float)(monster->start[0] - monster->end[0]);
	normal[2] = 0.0;
	d = normal[0] * monster->start[0] + normal[1] * monster->start[1];
	div = scalar_product_3(ray_dir, normal);
	if (float_equality(div, 0.0) == false)
	{
		*lambda = (d - scalar_product_3(ray_origin, normal)) / div;
		if (*lambda > 0.0)
			return (true);
	}
	return (false);
}

t_bool		glp(float *lambda, float ray_origin[3], float ray_dir[3],
		t_pickup *pickup)
{
	float div;
	float normal[3];
	float d;

	normal[0] = (float)(pickup->end[1] - pickup->start[1]);
	normal[1] = (float)(pickup->start[0] - pickup->end[0]);
	normal[2] = 0.0;
	d = normal[0] * pickup->start[0] + normal[1] * pickup->start[1];
	div = scalar_product_3(ray_dir, normal);
	if (float_equality(div, 0.0) == false)
	{
		*lambda = (d - scalar_product_3(ray_origin, normal)) / div;
		if (*lambda > 0.0)
			return (true);
	}
	return (false);
}
