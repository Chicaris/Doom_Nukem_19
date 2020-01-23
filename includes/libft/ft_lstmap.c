/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 09:26:49 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/23 11:56:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newelem;

	newelem = (t_list *)malloc(sizeof(t_list));
	if (!newelem || !f)
		return (NULL);
	newelem = f(lst);
	if (lst->next)
	{
		newelem->next = ft_lstmap(lst->next, f);
		if (newelem->next == NULL)
		{
			free(newelem);
			return (NULL);
		}
	}
	else
		newelem->next = NULL;
	return (newelem);
}
