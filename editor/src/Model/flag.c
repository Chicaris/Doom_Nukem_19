/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:36:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 10:44:14 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_flag			*flag_cpy(t_flag *src)
{
	t_flag		*dest;

	if (src == NULL)
		return (NULL);
	else
	{
		if (!(dest = (t_flag *)malloc(sizeof(t_flag))))
			return (NULL);
		dest->texture = src->texture;
		dest->top[0] = src->top[0];
		dest->top[1] = src->top[1];
		dest->top[2] = src->top[2];
		dest->width = src->width;
		dest->heigth = src->heigth;
	}
	return (dest);
}

t_bool			add_flag(t_core *core, int wall_idx, t_flag *flag)
{
	int				i;
	t_wall_lst		*curr;

	i = 0;
	curr = core->wall_list;
	while (i != wall_idx && curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	if (curr != NULL && curr->wall != NULL)
		curr->wall->flag = flag_cpy(flag);
	else
		return (false);
	return (true);
}
