/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:41:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/24 13:30:13 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool		check_header(int fd)
{
	char buffer[5];

	if (read(fd, buffer, 4) < 1)
	{
		printf("read failed check_header\n");
		return (false);
	}
	buffer[4] = 0;
	if (buffer[0] != 'W' || buffer[1] != '3' || buffer[2] != 'D' ||
			buffer[3] != 'F')
		return (false);
	return (true);
}

t_bool		load_player(t_core *core, int fd)
{
	if (read(fd, &(core->player->position[0]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(core->player->position[1]), sizeof(float)) != sizeof(float))
		return (false);
	if (read(fd, &(core->player->position[2]), sizeof(float)) != sizeof(float))
		return (false);
	return (true);
}

t_bool		load_sector_list(t_core *core, int fd)
{
	int				i;
	int				num_sectors;
	unsigned char	*buffer;
	int				bp;
	t_sector		buffer_sector;

	bp = 0;
	if (read(fd, &num_sectors, sizeof(unsigned)) != sizeof(unsigned))
		error_msg("read failed\n");
	if (!(buffer = malloc((num_sectors * sizeof(t_sector)))))
		error_msg("malloc failed load sector\n");
	if (read(fd, buffer, num_sectors * sizeof(t_sector)) !=
			(sizeof(t_sector) * num_sectors))
		error_msg("read failed\n");
	i = 0;
	while (i < num_sectors)
	{
		ft_memcpy(&buffer_sector, buffer + bp, sizeof(t_sector));
		bp += sizeof(t_sector);
		add_sector(core, &buffer_sector);
		i++;
	}
	return (true);
}

t_bool		load_monster_list(t_core *core, int fd)
{
	int			i;
	int			nbr_monster;
	char		*buffer;
	int			bp;
	t_monster	buffer_monster;

	bp = 0;
	if (read(fd, &nbr_monster, sizeof(int)) != sizeof(int))
		error_msg("read failed\n");
	if (!(buffer = (char *)malloc(sizeof(t_monster) * nbr_monster)))
		error_msg("malloc failed load wall\n");
	if (read(fd, buffer, sizeof(t_monster) * nbr_monster) !=
			(sizeof(t_monster) * nbr_monster))
		error_msg("read failed\n");
	i = 0;
	while (i < nbr_monster)
	{
		ft_memcpy(&buffer_monster, buffer + bp, sizeof(t_monster));
		bp += sizeof(t_monster);
		add_monster(core, &buffer_monster);
		i++;
	}
	return (true);
}

t_bool		load_pickup_list(t_core *core, int fd)
{
	int			i;
	int			nbr_pickup;
	char		*buffer;
	int			bp;
	t_pickup	buffer_pickup;

	bp = 0;
	if (read(fd, &nbr_pickup, sizeof(int)) != sizeof(int))
		error_msg("read failed\n");
	if (!(buffer = (char *)malloc(sizeof(t_pickup) * nbr_pickup)))
		error_msg("malloc failed load wall\n");
	if (read(fd, buffer, sizeof(t_pickup) * nbr_pickup) !=
			(sizeof(t_pickup) * nbr_pickup))
		error_msg("read failed\n");
	i = 0;
	while (i < nbr_pickup)
	{
		ft_memcpy(&buffer_pickup, buffer + bp, sizeof(t_pickup));
		bp += sizeof(t_pickup);
		add_pickup(core, &buffer_pickup);
		i++;
	}
	return (true);
}
