/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:36:14 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/29 10:08:29 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_flag			*flag_cpy(t_flag *src)
{
	t_flag		*dest;

	if (src == NULL)
		return (NULL);
	else
	{
		if (!(dest = (t_flag *)malloc(sizeof(t_flag))))
			return (NULL);
		memset(dest, 0, sizeof(t_flag));
		dest->texture = src->texture;
		dest->top[0] = src->top[0];
		dest->top[1] = src->top[1];
		dest->top[2] = src->top[2];
		dest->width = src->width;
		dest->heigth = src->heigth;
	}
	return (dest);
}
