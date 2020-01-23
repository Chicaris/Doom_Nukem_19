/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pickup1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:58:44 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 13:58:46 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool		clip_pickup(float intersection[3], t_pickup *pickup)
{
	if (((intersection[0] - (float)pickup->start[0]) *
				(intersection[0] - (float)pickup->end[0]) <= INTERSECT_TOL)
			&& ((intersection[1] - (float)pickup->start[1]) *
				(intersection[1] - (float)pickup->end[1]) <= INTERSECT_TOL)
			&& (intersection[2] >= pickup->floor)
			&& (intersection[2] <= pickup->ceil))
		return (true);
	return (false);
}
