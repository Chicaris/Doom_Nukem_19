/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:38:44 by hde-moff          #+#    #+#             */
/*   Updated: 2019/11/20 11:56:58 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

static t_bool		init_file(t_core *core, char *filename)
{
	if (!(core->file = (char *)malloc(sizeof(char)
					* (ft_strlen(filename) + 1))))
		return (false);
	core->file = ft_strcpy(core->file, filename);
	return (true);
}

static void			init_core2(t_core *core)
{
	init_pickup_list(core);
	core->mode = camera;
	core->debug = 0;
	core->fly_mode = false;
	core->game_status = menu;
	core->selected = 0;
	core->step_door = 0.75;
	core->door_status = 1;
	core->sky_status = 1;
	core->step_status = 0;
}

static t_bool	check_player(t_core *core)
{
	if ((float_equality(core->level.origin_player[0], 0.0) == true)
			&& (float_equality(core->level.origin_player[1], 0.0) == true)
			&& (float_equality(core->level.origin_player[2], 0.0) == true))
		return (false);
	return (true);
}

t_bool			init_core(t_core *core)
{
	if (sdl_init(core) != true)
		return (false);
	if (load_level_data(core) != true)
		return (false);
	if (check_player(core) != true)
		return (false);
	if (init_sound(core) != true)
		return (false);
	if (init_world(core) != true)
		return (false);
	if (init_camera(core) != true)
		return (false);
	if (init_items(core) != true)
		return (false);
	if (init_player(core) != true)
		return (false);
	if (init_weapon(core) != true)
		return (false);
	init_core2(core);
	return (true);
}

int				main(int argc, char **argv)
{
	t_core core;

	ft_memset(&core, 0, sizeof(t_core));
	if (argc != 2)
		error_msg(&core, "use: ./doom-nukem [valid *.w3d file]\n");
	if (init_file(&core, argv[1]) == true)
	{
		if (init_core(&core) == true)
			mainloop(&core);
		else
			error_msg(&core, "Don't init core correctly\n");
	}
	else
		error_msg(&core, "Don't init core correctly\n");
	return (0);
}
