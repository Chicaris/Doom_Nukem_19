/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:59:33 by bruno             #+#    #+#             */
/*   Updated: 2018/10/22 15:27:47 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*fresh;
	int		i;

	len = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	if ((fresh = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	fresh[len] = '\0';
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
