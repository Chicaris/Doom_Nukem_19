/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:12:50 by bruno             #+#    #+#             */
/*   Updated: 2018/10/22 15:29:45 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*fresh;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(fresh = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	fresh[len] = '\0';
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
