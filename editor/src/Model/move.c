/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:39:23 by cbruno            #+#    #+#             */
/*   Updated: 2019/09/12 12:40:08 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

void		move_center(t_core *core, int step[2])
{
	core->grid->center[0] += step[0];
	core->grid->center[1] += step[1];
	core->grid->first_click[0] += step[0];
	core->grid->first_click[1] += step[1];
	core->grid->second_click[0] += step[0];
	core->grid->second_click[1] += step[1];
}
