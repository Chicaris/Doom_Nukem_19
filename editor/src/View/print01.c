/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:28:04 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 13:28:05 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		error_msg(char *str)
{
	printf("%s", str);
	exit(0);
}

void		print_grid(t_grid *grid)
{
	printf("center:\t\t(%i %i)\n", grid->center[0], grid->center[1]);
}

void		print_flag(t_flag *flag)
{
	printf("FLAG :\n");
	if (flag == NULL)
		printf("flag = NULL\n");
	else
	{
		printf("texture :\t\t%i\n", flag->texture);
		printf("origin :\t\t(%f %f %f)\n", flag->top[0],
				flag->top[1], flag->top[2]);
		printf("Width :\t\t%f\n", flag->width);
		printf("Heigth :\t\t%f\n", flag->heigth);
	}
}

void		print_monster(t_monster *monster)
{
	printf("texture :\t\t%i\n", monster->texture);
	printf("origin :\t\t(%f %f %f)\n", monster->origin[0],
			monster->origin[1], monster->origin[2]);
	printf("sector_idx :\t\t%i\n", monster->sector_idx);
}

void		print_monster_list(t_monster_lst *monster_list)
{
	while (monster_list != NULL)
	{
		print_monster(monster_list->monster);
		monster_list = monster_list->next;
	}
}
