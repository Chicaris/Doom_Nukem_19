/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:30:57 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/23 11:56:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next;
	t_list		*curr;

	if (del && *alst)
	{
		curr = *alst;
		while (curr != NULL)
		{
			next = curr->next;
			(*del)(curr->content, curr->content_size);
			free(curr);
			curr = next;
		}
		*alst = NULL;
	}
}
