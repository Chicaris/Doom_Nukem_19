/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:46:36 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 16:44:20 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_sect_list		*create_sector(t_core *core, int idx)
{
	t_sect_list		*self;

	if (!(self = (t_sect_list *)malloc(sizeof(t_sect_list))))
		return (NULL);
	ft_memset(self, 0, sizeof(t_sect_list));
	self->idx = idx;
	self->visible = 1;
	self->sector = core->level.sectors[idx];
	if ((self->wall_list = init_walls(core, idx)) == NULL)
		error_msg(core, "failed init_walls");
	self->next = NULL;
	return (self);
}

t_sect_list		*get_sector_in(t_core *core)
{
	t_sect_list		*world;
	int				idx;

	idx = 0;
	world = core->world;
	while (world != NULL)
	{
		if (idx == core->sector_in)
			return (world);
		world = world->next;
		idx++;
	}
	return (NULL);
}

t_bool			init_world(t_core *core)
{
	unsigned int	i;
	t_sect_list		*self;
	t_sect_list		*tmp;

	i = 1;
	if ((self = create_sector(core, 0)) == NULL)
		return (false);
	tmp = self;
	while (i < core->level.num_sectors)
	{
		if ((tmp->next = create_sector(core, i)) == NULL)
			return (false);
		tmp = tmp->next;
		i++;
	}
	core->world = self;
	return (true);
}
