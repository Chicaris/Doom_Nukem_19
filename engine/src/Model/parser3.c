/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:43:13 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 11:51:08 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static t_bool	read_texture(int fd, t_level_data *level_data, unsigned int i)
{
	void			*pixel_buffer;
	int				format[3];
	unsigned char	bpp;
	int				masks[4];

	if (read(fd, &format, sizeof(int) * 3) < 1)
		return (false);
	if (read(fd, &bpp, sizeof(unsigned char)) < 1)
		return (false);
	if (read(fd, masks, sizeof(int) * 4) < 1)
		return (false);
	if (!(pixel_buffer = (void *)malloc(format[2] * format[1])))
		return (false);
	if (read(fd, pixel_buffer, format[2] * format[1])
			!= (format[2] * format[1]))
		return (false);
	level_data->textures[i] = SDL_CreateRGBSurfaceFrom(pixel_buffer,
			format[0], format[1], bpp,
			format[2], masks[0], masks[1], masks[2], masks[3]);
	if (level_data->textures[i] == NULL)
		return (false);
	return (true);
}

t_bool			load_textures(int fd, t_level_data *level_data)
{
	unsigned		i;

	if (read(fd, &level_data->num_textures, sizeof(unsigned)) < 1)
		return (false);
	level_data->textures = NULL;
	if (!(level_data->textures = (SDL_Surface **)malloc(level_data->num_textures
					* sizeof(SDL_Surface *))))
		return (false);
	ft_memset(level_data->textures, 0, level_data->num_textures
			* sizeof(SDL_Surface *));
	i = 0;
	while (i < level_data->num_textures)
	{
		if (read_texture(fd, level_data, i) != true)
			return (false);
		i++;
	}
	return (true);
}

static t_bool	read_audio(int fd, t_level_data *level_data, unsigned int i)
{
	int			ret;
	int			allocated;
	unsigned	alen;
	Uint8		*raw;

	if ((ret = read(fd, &allocated, sizeof(int))) < 1)
		return (false);
	if (read(fd, &alen, sizeof(unsigned)) < 1)
		return (false);
	if (!(raw = malloc(alen)))
		return (false);
	if ((ret = read(fd, raw, alen)) < 1)
		return (false);
	if (!(level_data->samples[i] = Mix_QuickLoad_RAW(raw, alen)))
		return (false);
	return (true);
}

t_bool			load_audio(int fd, t_level_data *level_data)
{
	unsigned i;

	i = 0;
	if (read(fd, &level_data->num_audio, sizeof(unsigned)) < 1)
		return (false);
	level_data->samples = NULL;
	if (!(level_data->samples =
				malloc(level_data->num_audio * sizeof(Mix_Chunk *))))
		return (false);
	while (i < level_data->num_audio)
	{
		if (read_audio(fd, level_data, i) != true)
			return (false);
		i++;
	}
	return (true);
}

t_bool			load_ttf(int fd, t_level_data *level_data)
{
	unsigned int			i;
	unsigned				len_font;
	char					*path;

	i = 0;
	if (read(fd, &level_data->num_ttf, sizeof(unsigned)) < 1)
		return (false);
	while (i < level_data->num_ttf)
	{
		if (read(fd, &len_font, sizeof(unsigned)) < 1)
			return (false);
		if (!(path = (char *)malloc(sizeof(char) * (len_font + 1))))
			return (false);
		path[len_font] = '\0';
		if (read(fd, path, sizeof(char) * (len_font)) < 1)
			return (false);
		level_data->ttf_path[i] = path;
		i++;
	}
	return (true);
}
