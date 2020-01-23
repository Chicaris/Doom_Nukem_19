/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:16:07 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:31:31 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

SDL_Color		int_to_rgb(uint32_t color)
{
	SDL_Color	rgb;

	rgb.a = (color >> 24);
	rgb.r = (color >> 16);
	rgb.g = (color >> 8);
	rgb.b = color;
	return (rgb);
}

SDL_Surface		*get_texte(char *txt, char *font, SDL_Color color,
		unsigned scale)
{
	SDL_Surface	*texte;
	TTF_Font	*police;

	texte = NULL;
	police = NULL;
	police = TTF_OpenFont(font, scale);
	texte = TTF_RenderText_Blended(police, txt, color);
	TTF_CloseFont(police);
	return (texte);
}

t_bool			init_font(t_core *core)
{
	if ((core->ttf_path[0] =
				ft_strdup("../editor/res/fonts/Special.ttf")) == NULL)
		return (false);
	if ((core->ttf_path[1] = ft_strdup("../editor/res/fonts/Doom.ttf")) == NULL)
		return (false);
	return (true);
}
