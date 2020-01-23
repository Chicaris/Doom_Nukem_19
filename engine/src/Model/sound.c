/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:01:44 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:13:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_bool		init_sound(t_core *core)
{
	if (Mix_PlayChannel(0, core->level.samples[0], -1) == -1)
	{
		ft_putstr("Error: Mix_playChannel\n");
		return (false);
	}
	core->music_status = 1;
	return (true);
}
