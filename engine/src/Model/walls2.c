/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:08:43 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/15 15:08:45 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void			door_move(t_core *core)
{
	if (core->door_status == 0)
	{
		if (core->step_door > 0.0)
			core->step_door -= 0.1;
	}
	else
	{
		if (core->step_door < 1.0)
			core->step_door += 0.1;
	}
}

int				get_lenght_list(t_wall_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

float			get_distance(float origin[3], float inter[2])
{
	float		a;
	float		b;

	a = inter[0] - origin[0];
	b = inter[1] - origin[1];
	return (sqrtf(a * a + b * b));
}

void			concat_wall_list(t_wall_list *begin, t_wall_list *end)
{
	while (begin->next != NULL)
		begin = begin->next;
	begin->next = end;
}
