/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:13:07 by bruno             #+#    #+#             */
/*   Updated: 2018/10/22 16:17:18 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	int		i;

	if (!s || (!(fresh = malloc((len + 1) * sizeof(char)))))
		return (NULL);
	i = 0;
	fresh[len] = '\0';
	while (len--)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
