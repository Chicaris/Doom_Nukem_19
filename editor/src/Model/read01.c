/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:41:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:25:20 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool		load_wall(int fd, t_wall *buffer_wall)
{
	if (read(fd, &(buffer_wall->start[0]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(buffer_wall->start[1]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(buffer_wall->end[0]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(buffer_wall->end[1]), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(buffer_wall->next_sector), sizeof(int)) != sizeof(int))
		return (false);
	if (read(fd, &(buffer_wall->b_texture), sizeof(unsigned)) !=
			sizeof(unsigned))
		return (false);
	if (read(fd, &(buffer_wall->m_texture), sizeof(unsigned)) !=
			sizeof(unsigned))
		return (false);
	if (read(fd, &(buffer_wall->t_texture), sizeof(unsigned)) !=
			sizeof(unsigned))
		return (false);
	return (true);
}

t_bool		load_flag(int fd, t_wall *buffer_wall)
{
	t_flag	flag;

	if (read(fd, &(flag.texture), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(flag.top[0]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag.top[1]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag.top[1]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag.width), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(flag.heigth), sizeof(float)) != sizeof(float))
		return (false);
	buffer_wall->flag = flag_cpy(&flag);
	return (true);
}

t_bool		load_wall_list(t_core *core, int fd)
{
	int		i;
	int		num_walls;
	t_wall	buffer_wall;
	int		tmp;

	if (read(fd, &num_walls, sizeof(int)) != sizeof(int))
		error_msg("read failed\n");
	i = 0;
	while (i < num_walls)
	{
		if (load_wall(fd, &buffer_wall) == false)
			return (false);
		if (read(fd, &(tmp), sizeof(int)) != sizeof(int))
			return (false);
		if (tmp == 1)
		{
			if (load_flag(fd, &buffer_wall) == false)
				return (false);
		}
		else
			buffer_wall.flag = NULL;
		add_wall(core, &buffer_wall);
		i++;
	}
	return (true);
}

t_bool		read_file(t_core *core, char *filename)
{
	int		fd;

	if (!(fd = open(filename, O_RDONLY)))
		return (false);
	if (check_header(fd) == true)
	{
		if (load_sector_list(core, fd) != true)
			return (false);
		if (load_wall_list(core, fd) != true)
			return (false);
		if (load_player(core, fd) != true)
			return (false);
		if (load_monster_list(core, fd) != true)
			return (false);
		if (load_pickup_list(core, fd) != true)
			return (false);
	}
	close(fd);
	return (true);
}
