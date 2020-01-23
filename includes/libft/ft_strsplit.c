/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:02:09 by bruno             #+#    #+#             */
/*   Updated: 2018/10/23 11:17:11 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lim(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_ofwords;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nb_ofwords = ft_nbofwords((char *)s, c);
	if (!(tab = (char **)malloc((nb_ofwords + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (nb_ofwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_lim((char *)s, c));
		if (!tab[i])
		{
			free(tab);
			return (NULL);
		}
		s = s + ft_lim((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
