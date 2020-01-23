/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:42:30 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 12:43:25 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void		key_down(t_core *core, SDL_KeyboardEvent key)
{
	key_arrow(core, key);
	key_move(core, key);
	key_down3(core, key);
	key_return(core, key);
}
