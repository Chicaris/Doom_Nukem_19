/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:19:57 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/23 11:55:03 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_addback(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*head;

	if (!*alst || !new)
		return ;
	tmp = *alst;
	head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*alst = head;
}
