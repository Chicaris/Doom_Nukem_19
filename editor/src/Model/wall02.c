/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:39 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 14:16:46 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

int				get_nbr_wall(t_wall_lst *wall_list, int start)
{
	int		nbr;

	nbr = start;
	while (wall_list != NULL)
	{
		nbr++;
		wall_list = wall_list->next;
	}
	return (nbr);
}

t_wall_lst		*get_last_wall(t_core *core)
{
	t_wall_lst		*curr;

	curr = core->wall_list;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

t_wall_lst		*get_wall_list(t_core *core, int start)
{
	int				i;
	t_wall_lst		*current;

	i = 0;
	current = core->wall_list;
	while (i < start && current != NULL)
	{
		current = current->next;
		i++;
	}
	return (current);
}
