/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:28:21 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/08 11:59:30 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int size;

	size = ft_strlen(to_find);
	if (size <= 0)
	{
		return ((char *)str);
	}
	while (*str)
	{
		if (ft_strncmp(str, to_find, size) == 0)
		{
			return ((char *)str);
		}
		str++;
	}
	return (0);
}
