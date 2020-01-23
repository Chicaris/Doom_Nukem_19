/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:30:33 by bruno             #+#    #+#             */
/*   Updated: 2018/10/11 10:00:23 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	strjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!strjoin)
		return (NULL);
	ft_strcpy(strjoin, (char *)s1);
	ft_strcat(strjoin, (char *)s2);
	return (strjoin);
}
