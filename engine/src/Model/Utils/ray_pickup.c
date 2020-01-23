/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pickup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:53:52 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/15 14:02:35 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

static void		ray_inter(float intersection[3], t_core *core,
		float lb[2], float ray[3])
{
	vector_init(intersection,
			core->camera.origin[0] + lb[0] * ray[0],
			core->camera.origin[1] + lb[0] * ray[1],
			core->camera.origin[2] + lb[0] * ray[2]);
}

static void		ray_cp(float lb[2], t_pickup *pickup[2], float cl[3],
		float inter[3])
{
	lb[1] = lb[0];
	pickup[1] = pickup[0];
	vector_cpy(cl, inter);
}

static t_bool	ray_tst(t_core *core, float intersection[3],
		float off[2], t_pickup *pickup)
{
	if (clip_pickup(intersection, pickup) == true)
		if ((get_pixel(core->level.textures[pickup->texture],
						off[0], off[1]) & RMASK) != 0)
			return (true);
	return (false);
}

static t_bool	ray_tst2(t_core *core, t_pickup *pickup,
		float lb[2], float ray[3])
{
	if (pickup->sector_idx == core->sector_in)
		if (glp(&lb[0], core->camera.origin, ray, pickup) == true)
			if ((lb[0] < lb[1]) || (lb[1] < 0))
				return (true);
	return (false);
}

t_pickup		*ray_pickup(t_core *core, float intersection[3], float ray[3])
{
	float			lb[2];
	float			cl[3];
	t_pickup		*pickup[2];
	t_pickup_lst	*pickup_list;
	float			off[2];

	lb[1] = -1;
	pickup[1] = NULL;
	pickup_list = core->level.pickup_list;
	while (pickup_list != NULL)
	{
		pickup[0] = pickup_list->pickup;
		if (ray_tst2(core, pickup[0], lb, ray) == true)
		{
			ray_inter(intersection, core, lb, ray);
			gtop(pickup[0], intersection, off);
			if (ray_tst(core, intersection, off, pickup[0]) == true)
				ray_cp(lb, pickup, cl, intersection);
		}
		pickup_list = pickup_list->next;
	}
	vector_cpy(intersection, cl);
	return (pickup[1]);
}
