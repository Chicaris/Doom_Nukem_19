/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:52:04 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/08 12:44:28 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	char	*s12;
	char	*s22;

	s12 = (char *)s1;
	s22 = (char *)s2;
	if (n == 0)
		return (0);
	while (--n && *s12 == *s22 && *s12 != '\0')
	{
		s12++;
		s22++;
	}
	return ((unsigned char)*s12 - (unsigned char)*s22);
}
