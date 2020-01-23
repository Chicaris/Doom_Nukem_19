/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:57:49 by bruno             #+#    #+#             */
/*   Updated: 2018/10/22 15:21:22 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if ((str = ((void *)malloc(size))) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}
