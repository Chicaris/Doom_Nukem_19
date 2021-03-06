/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:16:13 by hde-moff          #+#    #+#             */
/*   Updated: 2019/11/20 11:16:03 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static t_bool	check_header(int fd)
{
	char buffer[5];

	if (read(fd, buffer, 4) < 1)
	{
		ft_putstr("read failed\n");
		return (false);
	}
	buffer[4] = 0;
	if (!(ft_strequ("W3DF", buffer)))
	{
		ft_putstr("Wrong file, use only files generated by doomED\n");
		return (false);
	}
	return (true);
}

static t_bool	load_level_data2(int fd, t_level_data *level_data)
{
	if (load_sectors(fd, level_data) != true)
		return (false);
	if (level_data->num_sectors == 0)
		return (false);
	if (load_walls(fd, level_data) != true)
		return (false);
	if (load_player(fd, level_data) != true)
		return (false);
	if (load_monster_list(level_data, fd) != true)
		return (false);
	if (load_pickup_list(level_data, fd) != true)
		return (false);
	if (load_textures(fd, level_data) != true)
		return (false);
	if (load_audio(fd, level_data) != true)
		return (false);
	if (load_ttf(fd, level_data) != true)
		return (false);
	return (true);
}

t_bool			load_level_data(t_core *core)
{
	t_level_data	level_data;
	int				fd;

	ft_memset(&level_data, 0, sizeof(t_level_data));
	if (!(fd = open(core->file, O_RDONLY)))
		return (false);
	if (check_header(fd) != true)
		return (false);
	if (load_level_data2(fd, &level_data) != true)
		return (false);
	if (close(fd) == -1)
		return (false);
	ft_memcpy(&core->level, &level_data, sizeof(t_level_data));
	return (true);
}
