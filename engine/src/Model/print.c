/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:58:35 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 11:26:31 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static void		print_line(char *character, int iter)
{
	int		i;

	i = 0;
	while (i < iter)
	{
		ft_putstr(character);
		i++;
	}
}

void			print_menu(void)
{
	ft_putstr("e[1;1H\e[2J\n");
	print_line("=", 128);
	ft_putstr("\n");
	ft_putstr("\n");
	print_line(" ", 45);
	ft_putstr("WELCOME IN OUR DOOM\n");
	print_line(" ", 45);
	ft_putstr("By cbruno and rgauthie\n");
	ft_putstr("\n");
	print_line("=", 128);
	ft_putstr("\n");
	ft_putstr("ESC:\t\tQuit\n");
	ft_putstr("WASD:\t\tMove\n");
	ft_putstr("ARROWS:\t\tRotation\n");
	ft_putstr("Shift:\t\tSquat\n");
	ft_putstr("E:\t\tOpen door\n");
	ft_putstr("R:\t\tReload\n");
	ft_putstr("C:\t\tSkybox\n");
	ft_putstr("T:\t\tMenu pause\n");
	ft_putstr("M:\t\tMute musique\n");
	ft_putstr("L:\t\tScanner mode\n");
}

void			error_msg(t_core *core, char *msg)
{
	ft_putstr(msg);
	free_all(core);
	exit(0);
}
