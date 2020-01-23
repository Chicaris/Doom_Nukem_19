/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:38:07 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 11:20:03 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_bool			load_player(int fd, t_level_data *level_data)
{
	if (read(fd, &level_data->origin_player[0], sizeof(float)) != sizeof(float))
	{
		ft_putstr("read failed\n");
		return (false);
	}
	if (read(fd, &level_data->origin_player[1], sizeof(float)) != sizeof(float))
	{
		ft_putstr("read failed\n");
		return (false);
	}
	if (read(fd, &level_data->origin_player[2], sizeof(float)) != sizeof(float))
	{
		ft_putstr("read failed\n");
		return (false);
	}
	return (true);
}

t_bool			load_monster_list(t_level_data *level_data, int fd)
{
	int			i;
	char		*buffer;
	int			bp;
	t_monster	buffer_monster;
	int			nm;

	bp = 0;
	if (read(fd, &nm, sizeof(int)) != sizeof(int))
		return (false);
	if (!(buffer = (char *)malloc(sizeof(t_monster) * nm)))
		return (false);
	if (read(fd, buffer, sizeof(t_monster) * nm) != (sizeof(t_monster) * nm))
		return (false);
	i = 0;
	while (i < nm)
	{
		ft_memcpy(&buffer_monster, buffer + bp, sizeof(t_monster));
		bp += sizeof(t_monster);
		if (add_monster(level_data, &buffer_monster) != true)
			return (false);
		i++;
	}
	return (true);
}

t_bool			load_pickup_list(t_level_data *level_data, int fd)
{
	int			i;
	int			np;
	char		*buffer;
	int			bp;
	t_pickup	buffer_pickup;

	bp = 0;
	if (read(fd, &np, sizeof(int)) != sizeof(int))
		return (false);
	if (!(buffer = (char *)malloc(sizeof(t_pickup) * np)))
		return (false);
	if (read(fd, buffer, sizeof(t_pickup) * np) != (sizeof(t_pickup) * np))
		return (false);
	i = 0;
	while (i < np)
	{
		ft_memcpy(&buffer_pickup, buffer + bp, sizeof(t_pickup));
		bp += sizeof(t_pickup);
		if (add_pickup(level_data, &buffer_pickup) != true)
			return (false);
		i++;
	}
	return (true);
}

static t_bool	read_sector(int fd, t_sector *sector)
{
	ft_memset(sector, 0, sizeof(t_sector));
	if (read(fd, &(sector->start_wall), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(sector->num_walls), sizeof(unsigned)) != sizeof(unsigned))
		return (false);
	if (read(fd, &(sector->floor_height), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(sector->ceiling_height), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(sector->floor_texture), sizeof(unsigned))
			!= sizeof(unsigned))
		return (false);
	if (read(fd, &(sector->ceiling_texture), sizeof(unsigned))
			!= sizeof(unsigned))
		return (false);
	sector->floor_height *= STEP;
	sector->ceiling_height *= STEP;
	return (true);
}

t_bool			load_sectors(int fd, t_level_data *level_data)
{
	unsigned int	i;
	t_sector		sector;
	size_t			total_size;

	if (read(fd, &level_data->num_sectors, sizeof(unsigned)) < 1)
		return (false);
	total_size = level_data->num_sectors * sizeof(t_sector);
	if (!(level_data->sectors = (t_sector *)malloc(total_size)))
		return (false);
	ft_memset(level_data->sectors, 0, total_size);
	i = 0;
	while (i < level_data->num_sectors)
	{
		if (read_sector(fd, &sector) != true)
			return (false);
		ft_memcpy(&level_data->sectors[i], &sector, sizeof(t_sector));
		i++;
	}
	return (true);
}
