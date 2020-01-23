/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:17:01 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:37:09 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool					write_flag_2(int fd, t_flag *flag)
{
	if (!(write(fd, &flag->texture, sizeof(unsigned))))
		return (false);
	if (!(write(fd, &flag->top[0], sizeof(float))))
		return (false);
	if (!(write(fd, &flag->top[1], sizeof(float))))
		return (false);
	if (!(write(fd, &flag->top[0], sizeof(float))))
		return (false);
	if (!(write(fd, &flag->width, sizeof(float))))
		return (false);
	if (!(write(fd, &flag->heigth, sizeof(float))))
		return (false);
	return (true);
}

t_bool					write_flag(t_flag *flag, int fd)
{
	int		i;

	if (flag == NULL)
	{
		i = 0;
		if (!(write(fd, &i, sizeof(int))))
			return (false);
	}
	else
	{
		i = 1;
		if (!(write(fd, &i, sizeof(int))))
			return (false);
		if (write_flag_2(fd, flag) == false)
			return (false);
	}
	return (true);
}

t_bool					write_wall_list_2(int fd, t_wall_lst *current)
{
	if (!(write(fd, &current->wall->start[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->wall->start[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->wall->end[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->wall->end[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->wall->next_sector, sizeof(int))))
		return (false);
	if (!(write(fd, &current->wall->b_texture, sizeof(unsigned))))
		return (false);
	if (!(write(fd, &current->wall->m_texture, sizeof(unsigned))))
		return (false);
	if (!(write(fd, &current->wall->t_texture, sizeof(unsigned))))
		return (false);
	if (write_flag(current->wall->flag, fd) != true)
		return (false);
	return (true);
}

t_bool					write_wall_list(t_core *core, int fd)
{
	t_wall_lst		*current;
	int				nbr_wall;

	current = core->wall_list;
	nbr_wall = get_nbr_wall(current, 0);
	if (!(write(fd, &nbr_wall, sizeof(int))))
		return (false);
	while (current != NULL)
	{
		if (write_wall_list_2(fd, current) == false)
			return (false);
		current = current->next;
	}
	return (true);
}
