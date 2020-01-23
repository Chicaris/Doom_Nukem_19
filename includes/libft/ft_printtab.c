/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:54:56 by cbruno            #+#    #+#             */
/*   Updated: 2019/03/04 16:28:49 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	if (!*tab)
		return ;
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}
