/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:43:48 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 15:23:09 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool		check_audio(t_core *core)
{
	int		i;

	i = 0;
	while (i < NUM_AUDIO)
	{
		if (core->audio[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

t_bool		load_audio(t_core *core)
{
	core->audio[0] = Mix_LoadWAV("res/audio/anitrasdance.wav");
	core->audio[1] = Mix_LoadWAV("res/audio/gameover.wav");
	core->audio[2] = Mix_LoadWAV("res/audio/gunshot.wav");
	core->audio[3] = Mix_LoadWAV("res/audio/demonshot.wav");
	core->audio[4] = Mix_LoadWAV("res/audio/pistolshot.wav");
	return (check_audio(core));
}
