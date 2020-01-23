/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_monster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:40:28 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 12:52:53 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

t_bool			clip_monster(float intersection[3], t_monster *monster)
{
	if (((intersection[0] - (float)monster->start[0]) *
				(intersection[0] - (float)monster->end[0]) <= INTERSECT_TOL)
			&& ((intersection[1] - (float)monster->start[1]) *
				(intersection[1] - (float)monster->end[1]) <= INTERSECT_TOL)
			&& (intersection[2] >= monster->floor)
			&& (intersection[2] <= monster->ceil))
		return (true);
	return (false);
}

static void		ray_cp(float lb[2], t_monster *m[2], float cl[3],
		float inter[3])
{
	lb[1] = lb[0];
	m[1] = m[0];
	vector_cpy(cl, inter);
}

static t_bool	ray_tst(t_core *core, float intersection[3],
		float off[2], t_monster *monster)
{
	if (clip_monster(intersection, monster) == true)
		if ((get_pixel(core->level.textures[monster->texture],
						off[0], off[1]) & RMASK) != 0)
			return (true);
	return (false);
}

static t_bool	ray_tst2(t_core *core, t_monster *m,
		float lb[2], float ray[3])
{
	if (m->sector_idx == core->sector_in)
		if (get_lambda_monster(&lb[0], core->camera.origin, ray, m) == true)
			if ((lb[0] < lb[1]) || (lb[1] < 0))
				return (true);
	return (false);
}

t_monster		*ray_monster(t_core *core, float intersection[3], float ray[3])
{
	float			lb[2];
	float			cl[3];
	t_monster		*m[2];
	t_monster_lst	*monster_list;
	float			off[2];

	lb[1] = -1;
	m[1] = NULL;
	monster_list = core->level.monster_list;
	while (monster_list != NULL)
	{
		m[0] = monster_list->monster;
		if (ray_tst2(core, m[0], lb, ray) == true)
		{
			vector_init(intersection, core->camera.origin[0] + lb[0] * ray[0],
					core->camera.origin[1] + lb[0] * ray[1],
					core->camera.origin[2] + lb[0] * ray[2]);
			get_texture_offset_monster(m[0], intersection, off);
			if (ray_tst(core, intersection, off, m[0]) == true)
				ray_cp(lb, m, cl, intersection);
		}
		monster_list = monster_list->next;
	}
	vector_cpy(intersection, cl);
	return (m[1]);
}
