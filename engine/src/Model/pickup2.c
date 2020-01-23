/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:19:31 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/09 18:23:21 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_bool		add_pickup(t_level_data *level_data, t_pickup *pickup)
{
	t_pickup_lst	*curr;

	curr = level_data->pickup_list;
	if (curr == NULL)
	{
		if (!(level_data->pickup_list =
				(t_pickup_lst *)malloc(sizeof(t_pickup_lst))))
			return (false);
		level_data->pickup_list->pickup = pickup_cpy(pickup);
		level_data->pickup_list->next = NULL;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (!(curr->next = (t_pickup_lst *)malloc(sizeof(t_pickup_lst))))
			return (false);
		curr->next->pickup = pickup_cpy(pickup);
		curr->next->next = NULL;
	}
	return (true);
}

void		delete_pickup(t_core *core, t_pickup *pickup)
{
	t_pickup_lst	*curr;
	t_pickup_lst	*prev;

	curr = core->level.pickup_list;
	if (curr != NULL && curr->pickup == pickup)
	{
		core->level.pickup_list = curr->next;
		free(curr->pickup);
		free(curr);
		return ;
	}
	while (curr != NULL && curr->pickup != pickup)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return ;
	prev->next = curr->next;
	free(curr->pickup);
	free(curr);
}
