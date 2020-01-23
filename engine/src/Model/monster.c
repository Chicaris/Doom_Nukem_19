/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:20:52 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 10:56:27 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		move_monster(t_core *core, t_monster *monster)
{
	float		dir[3];
	float		tmp[3];
	float		dist;

	dist = sqrtf((core->camera.origin[0] - monster->center[0]) *
			(core->camera.origin[0] - monster->center[0]) +
			(core->camera.origin[1] - monster->center[1]) *
			(core->camera.origin[1] - monster->center[1]));
	if (dist < 2 * STEP && dist > 32)
	{
		vector_diff(dir, monster->center, core->camera.origin);
		dir[2] = 0;
		vector_normalize(dir);
		vector_scale(dir, 4);
		vector_cpy(tmp, monster->center);
		vector_add(tmp, dir);
		if (check_mouvement(core, tmp, monster->sector_idx) == true)
		{
			vector_cpy(monster->center, tmp);
			if (dist < 48)
				update_life(core, -1);
		}
	}
}

void		move_monster_list(t_core *core)
{
	t_monster_lst	*curr;

	curr = core->level.monster_list;
	while (curr != NULL)
	{
		move_monster(core, curr->monster);
		curr = curr->next;
	}
}

void		change_monster(t_core *core, t_monster *monster)
{
	float	perp[3];
	float	tmp[3];

	monster->floor = monster->center[2];
	monster->ceil = monster->floor + core->level.textures[monster->texture]->h;
	monster->lookat[0] = core->camera.origin[0] - monster->center[0];
	monster->lookat[1] = core->camera.origin[1] - monster->center[1];
	monster->lookat[2] = 0.0;
	vector_normalize(monster->lookat);
	vector_init(perp, monster->lookat[1], -monster->lookat[0], 0.0);
	vector_cpy(tmp, perp);
	vector_scale(tmp, core->level.textures[monster->texture]->w / 2);
	monster->end[0] = tmp[0] + monster->center[0];
	monster->end[1] = tmp[1] + monster->center[1];
	monster->end[2] = monster->center[2];
	vector_cpy(tmp, perp);
	vector_scale(tmp, -core->level.textures[monster->texture]->w / 2);
	monster->start[0] = tmp[0] + monster->center[0];
	monster->start[1] = tmp[1] + monster->center[1];
	monster->start[2] = monster->center[2];
}

void		init_monster_list(t_core *core)
{
	t_monster_lst	*current;

	current = core->level.monster_list;
	while (current != NULL)
	{
		change_monster(core, current->monster);
		current = current->next;
	}
}

t_monster	*monster_cpy(t_monster *src)
{
	t_monster *dest;

	if (!(dest = (t_monster *)malloc(sizeof(t_monster))))
		return (NULL);
	memset(dest, 0, sizeof(t_monster));
	dest->texture = src->texture;
	dest->center[0] = src->center[0] * STEP;
	dest->center[1] = src->center[1] * STEP;
	dest->center[2] = src->center[2] * STEP;
	dest->sector_idx = src->sector_idx;
	return (dest);
}
