/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:04:21 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/18 14:38:40 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *oldbuffer, size_t buffersize)
{
	size_t		i;
	char		*newbuffer;

	newbuffer = (char *)malloc(buffersize * sizeof(char));
	if (oldbuffer != NULL)
	{
		if (newbuffer != NULL)
		{
			i = 0;
			while (i < buffersize)
			{
				newbuffer[i] = oldbuffer[i];
				i++;
			}
		}
		free(oldbuffer);
	}
	return (newbuffer);
}
