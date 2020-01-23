/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:23:36 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/08 10:46:16 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool			init_select(t_core *core)
{
	t_select	*select;

	if (!(select = (t_select *)malloc(sizeof(t_select))))
		return (false);
	ft_memset(select, 0, sizeof(t_select));
	select->wall = -1;
	select->sector = -1;
	select->monster = -1;
	select->pickup = -1;
	core->select = select;
	return (true);
}
