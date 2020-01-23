/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:28:21 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 17:09:44 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_wall_list		*create_wall(t_core *core, t_sector sector, int idx)
{
	t_wall_list		*self;

	if (!(self = (t_wall_list *)malloc(sizeof(t_wall_list))))
		return (NULL);
	memset(self, 0, sizeof(t_wall_list));
	self->visible = 1;
	self->floor = sector.floor_height;
	self->ceil = sector.ceiling_height;
	self->wall = core->level.walls[idx];
	self->lines = init_lines(core->level.walls[idx], sector.floor_height,
		sector.ceiling_height);
	if (self->lines == NULL)
		return (NULL);
	self->next = NULL;
	return (self);
}

t_wall_list		*init_walls(t_core *core, int idx)
{
	t_wall_list		*self;
	t_wall_list		*tmp;
	unsigned int	i;

	i = 1;
	if ((self = create_wall(core, core->level.sectors[idx],
				core->level.sectors[idx].start_wall)) == NULL)
		return (NULL);
	tmp = self;
	while (i < core->level.sectors[idx].num_walls)
	{
		tmp->next = create_wall(core, core->level.sectors[idx],
			core->level.sectors[idx].start_wall + i);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (self);
}

t_wall			*wall_cpy(t_wall *src)
{
	t_wall		*dest;

	if (!(dest = (t_wall *)malloc(sizeof(t_wall))))
		return (NULL);
	memset(dest, 0, sizeof(t_wall));
	dest->start[0] = src->start[0];
	dest->start[1] = src->start[1];
	dest->end[0] = src->end[0];
	dest->end[1] = src->end[1];
	dest->next_sector = src->next_sector;
	dest->b_texture = src->b_texture;
	dest->m_texture = src->m_texture;
	dest->t_texture = src->t_texture;
	dest->flag = flag_cpy(src->flag);
	return (dest);
}

t_bool			wall_equality(t_wall *dest, t_wall *src)
{
	if (src == NULL)
		return (false);
	if (dest->start[0] != src->start[0])
		return (false);
	if (dest->start[1] != src->start[1])
		return (false);
	if (dest->end[0] != src->end[0])
		return (false);
	if (dest->end[1] != src->end[1])
		return (false);
	if (dest->start[0] != src->end[0])
		return (false);
	if (dest->start[1] != src->end[1])
		return (false);
	return (true);
}
