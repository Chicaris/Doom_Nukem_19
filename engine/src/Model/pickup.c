/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:15:38 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/15 16:13:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		check_pickup_proximity(t_core *core, t_pickup *pickup)
{
	float dist;

	dist = sqrtf((core->camera.origin[0] - pickup->center[0]) *
			(core->camera.origin[0] - pickup->center[0]) +
			(core->camera.origin[1] - pickup->center[1]) *
			(core->camera.origin[1] - pickup->center[1]));
	if (dist < 50)
	{
		pick_up_item(core, pickup->item_id);
		delete_pickup(core, pickup);
	}
}

void		check_pickup_proximity_lst(t_core *core)
{
	t_pickup_lst	*current;

	current = core->level.pickup_list;
	while (current != NULL)
	{
		check_pickup_proximity(core, current->pickup);
		current = current->next;
	}
}

void		change_pickup(t_core *core, t_pickup *pickup)
{
	float	perp[3];
	float	tmp[3];

	pickup->floor = pickup->center[2];
	pickup->ceil = pickup->floor + core->level.textures[pickup->texture]->h;
	pickup->lookat[0] = core->camera.origin[0] - pickup->center[0];
	pickup->lookat[1] = core->camera.origin[1] - pickup->center[1];
	pickup->lookat[2] = 0.0;
	vector_normalize(pickup->lookat);
	vector_init(perp, pickup->lookat[1], -pickup->lookat[0], 0.0);
	vector_cpy(tmp, perp);
	vector_scale(tmp, core->level.textures[pickup->texture]->w / 2);
	pickup->end[0] = tmp[0] + pickup->center[0];
	pickup->end[1] = tmp[1] + pickup->center[1];
	pickup->end[2] = pickup->center[2];
	vector_cpy(tmp, perp);
	vector_scale(tmp, -core->level.textures[pickup->texture]->w / 2);
	pickup->start[0] = tmp[0] + pickup->center[0];
	pickup->start[1] = tmp[1] + pickup->center[1];
	pickup->start[2] = pickup->center[2];
}

void		init_pickup_list(t_core *core)
{
	t_pickup_lst	*current;

	current = core->level.pickup_list;
	while (current != NULL)
	{
		change_pickup(core, current->pickup);
		current = current->next;
	}
}

t_pickup	*pickup_cpy(t_pickup *src)
{
	t_pickup *dest;

	if (!(dest = (t_pickup *)malloc(sizeof(t_pickup))))
		return (NULL);
	memset(dest, 0, sizeof(t_pickup));
	dest->texture = src->texture;
	dest->item_id = src->item_id;
	dest->center[0] = src->center[0] * STEP;
	dest->center[1] = src->center[1] * STEP;
	dest->center[2] = src->center[2] * STEP;
	dest->sector_idx = src->sector_idx;
	return (dest);
}
