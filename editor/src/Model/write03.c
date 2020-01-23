/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:59:50 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 16:00:01 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool					write_monster_list(t_core *core, int fd)
{
	t_monster_lst		*current;
	int					nbr_monster;

	current = core->monster_list;
	nbr_monster = get_nbr_monster(core);
	if (!(write(fd, &nbr_monster, sizeof(int))))
		return (false);
	while (current != NULL)
	{
		if (write_monster_list_2(fd, current) == false)
			return (false);
		if (!(write(fd, &current->monster->origin[1], sizeof(float))))
			return (false);
		if (!(write(fd, &current->monster->origin[2], sizeof(float))))
			return (false);
		if (!(write(fd, &current->monster->lookat[0], sizeof(float))))
			return (false);
		if (!(write(fd, &current->monster->lookat[1], sizeof(float))))
			return (false);
		if (!(write(fd, &current->monster->lookat[2], sizeof(float))))
			return (false);
		current = current->next;
	}
	return (true);
}

static t_bool			write_pickup_list_2(int fd, t_pickup_lst *current)
{
	if (!(write(fd, &current->pickup->texture, sizeof(unsigned))))
		return (false);
	if (!(write(fd, &current->pickup->item_id, sizeof(int))))
		return (false);
	if (!(write(fd, &current->pickup->sector_idx, sizeof(int))))
		return (false);
	if (!(write(fd, &current->pickup->start[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->start[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->start[2], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->end[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->end[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->end[2], sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->ceil, sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->floor, sizeof(float))))
		return (false);
	if (!(write(fd, &current->pickup->center[0], sizeof(float))))
		return (false);
	return (true);
}

t_bool					write_pickup_list(t_core *core, int fd)
{
	t_pickup_lst		*current;
	int					nbr_pickup;

	current = core->pickup_list;
	nbr_pickup = get_nbr_pickup(core);
	if (!(write(fd, &nbr_pickup, sizeof(int))))
		return (false);
	while (current != NULL)
	{
		if (write_pickup_list_2(fd, current) == false)
			return (false);
		if (!(write(fd, &current->pickup->center[1], sizeof(float))))
			return (false);
		if (!(write(fd, &current->pickup->center[2], sizeof(float))))
			return (false);
		if (!(write(fd, &current->pickup->lookat[0], sizeof(float))))
			return (false);
		if (!(write(fd, &current->pickup->lookat[1], sizeof(float))))
			return (false);
		if (!(write(fd, &current->pickup->lookat[2], sizeof(float))))
			return (false);
		current = current->next;
	}
	return (true);
}
