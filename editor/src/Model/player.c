/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:13:25 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/08 10:48:16 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		set_player(t_core *core, float x, float y)
{
	t_sector_lst		*current;
	float				point[2];

	current = core->sector_list;
	point[0] = x;
	point[1] = y;
	while (current != NULL)
	{
		if (is_in_sector(core, current->sector, point) == true)
		{
			core->player->position[0] = x;
			core->player->position[1] = y;
			core->player->position[2] = current->sector->ceiling_height - 0.1;
		}
		current = current->next;
	}
}

t_bool		init_player(t_core *core)
{
	t_player	*self;

	if (!(self = (t_player *)malloc(sizeof(t_player))))
		return (false);
	ft_memset(self, 0, sizeof(t_player));
	self->position[0] = 0.0;
	self->position[1] = 0.0;
	self->position[2] = 0.0;
	core->player = self;
	return (true);
}
