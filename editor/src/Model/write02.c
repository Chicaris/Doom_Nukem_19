/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:17:04 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/20 12:01:32 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool			write_audio2(int fd, Mix_Chunk *audio,
		unsigned long *bp)
{
	if (!(write(fd, &audio->allocated, sizeof(int))))
		return (false);
	bp += sizeof(int);
	if (!(write(fd, &audio->alen, sizeof(unsigned))))
		return (false);
	bp += sizeof(unsigned);
	if (!(write(fd, audio->abuf, audio->alen)))
		return (false);
	bp += audio->alen;
	return (true);
}

t_bool			write_audio(t_core *core, int fd)
{
	Mix_Chunk		*audio;
	int				nbr_audio;
	unsigned		i;
	unsigned long	bp;

	nbr_audio = NUM_AUDIO;
	i = 0;
	if (!(write(fd, &nbr_audio, sizeof(unsigned))))
		return (false);
	bp = sizeof(unsigned);
	while (i < NUM_AUDIO)
	{
		audio = core->audio[i];
		if (write_audio2(fd, audio, &bp) != true)
			return (false);
		i++;
	}
	return (true);
}

t_bool			write_ttf(t_core *core, int fd)
{
	unsigned		nbr_font;
	unsigned		len_font;
	int				i;

	i = 0;
	nbr_font = NUM_TTF;
	if (!(write(fd, &nbr_font, sizeof(unsigned))))
		return (false);
	while (i < NUM_TTF)
	{
		len_font = ft_strlen(core->ttf_path[i]);
		if (!(write(fd, &len_font, sizeof(unsigned))))
			return (false);
		if (!(write(fd, core->ttf_path[i], sizeof(char) * (len_font))))
			return (false);
		i++;
	}
	return (true);
}

t_bool			write_file(t_core *core)
{
	int				fd;

	if ((fd = open(core->file, O_WRONLY | O_CREAT, S_IRWXU)) < 0)
		return (false);
	if (!(write(fd, "W3DF", 4)))
		return (false);
	if (write_sector_list(core, fd) != true)
		return (false);
	if (write_wall_list(core, fd) != true)
		return (false);
	if (write_player(core, fd) != true)
		return (false);
	if (write_monster_list(core, fd) != true)
		return (false);
	if (write_pickup_list(core, fd) != true)
		return (false);
	if (write_texture(core, fd) != true)
		return (false);
	if (write_audio(core, fd) != true)
		return (false);
	if (write_ttf(core, fd) != true)
		return (false);
	if (close(fd) == -1)
		return (false);
	return (true);
}
