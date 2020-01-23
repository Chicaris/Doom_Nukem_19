/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:41:08 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 11:50:34 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static t_bool		read_wall(int fd, t_wall *wall)
{
	ft_memset(wall, 0, sizeof(t_wall));
	if (read(fd, &(wall->start[0]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(wall->start[1]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(wall->end[0]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(wall->end[1]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(wall->next_sector), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(wall->b_texture), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(wall->m_texture), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(wall->t_texture), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	wall->start[0] *= STEP;
	wall->start[1] *= STEP;
	wall->end[0] *= STEP;
	wall->end[1] *= STEP;
	return (true);
}

static t_bool		read_flag(int fd, t_flag *flag)
{
	ft_memset(flag, 0, sizeof(t_flag));
	if (read(fd, &(flag->texture), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(flag->top[0]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag->top[1]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag->top[1]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag->width), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag->heigth), sizeof(float)) != sizeof(float))
		return (false);
	flag->top[0] *= STEP;
	flag->top[1] *= STEP;
	flag->top[2] *= STEP;
	return (true);
}

static t_bool		load_walls2(int fd, t_level_data *level_data,
		unsigned int i)
{
	int					tmp;
	t_wall				wall;
	t_flag				flag;

	if (read_wall(fd, &wall) != true)
		return (false);
	if (read(fd, &(tmp), sizeof(int)) != sizeof(int))
		return (false);
	if (tmp == 1)
	{
		if (read_flag(fd, &flag) != true)
			return (false);
		ft_memcpy(&wall.flag, &flag, sizeof(t_flag));
	}
	else
		wall.flag = NULL;
	ft_memcpy(&level_data->walls[i], &wall, sizeof(t_wall));
	return (true);
}

t_bool				load_walls(int fd, t_level_data *level_data)
{
	unsigned int		i;

	if (read(fd, &level_data->num_walls, sizeof(unsigned)) < 1)
		return (false);
	if (!(level_data->walls = (t_wall *)malloc(level_data->num_walls
					* sizeof(t_wall))))
		return (false);
	ft_memset(level_data->walls, 0, level_data->num_walls * sizeof(t_wall));
	i = 0;
	while (i < level_data->num_walls)
	{
		if (load_walls2(fd, level_data, i) != true)
			return (false);
		i++;
	}
	return (true);
}
