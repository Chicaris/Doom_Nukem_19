/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:16:08 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/11 15:50:37 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = dst;
	s2 = src;
	while (len--)
	{
		*s1 = *s2;
		if ((unsigned char)c == *s1)
			return (void *)(++s1);
		s1++;
		s2++;
	}
	return (NULL);
}
