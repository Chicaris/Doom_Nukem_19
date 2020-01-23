/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:27:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 13:52:05 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/editor.h"

t_bool	init_file(t_core *core, char *filename)
{
	if (!(core->file = (char *)malloc(sizeof(char)
					* (ft_strlen(filename) + 1))))
	{
		error_msg("Error malloc filename\n");
		return (false);
	}
	core->file = ft_strcpy(core->file, filename);
	return (true);
}

t_bool	init_core(t_core *core, char *filename)
{
	if (init_file(core, filename) != true)
		return (false);
	if (sdl_init(&core->sdl) != true)
		return (false);
	if (init_player(core) != true)
		return (false);
	if (init_select(core) != true)
		return (false);
	if (load_textures(core) != true)
		return (false);
	if (load_audio(core) != true)
		return (false);
	if (init_font(core) != true)
		return (false);
	if (read_file(core, filename) != true)
		return (false);
	if (init_grid(core) != true)
		return (false);
	core->option = draw;
	return (true);
}

int		main(int argc, char *argv[])
{
	t_core		core;

	ft_memset(&core, 0, sizeof(t_core));
	if (argc != 2)
		error_msg("usage: ./duked [valid *.w3d file]\n");
	else
	{
		if (init_core(&core, argv[1]) == true)
			mainloop(&core);
		else
		{
			error_msg("Don't init core correctly\n");
			free_all(&core);
		}
	}
	return (true);
}
