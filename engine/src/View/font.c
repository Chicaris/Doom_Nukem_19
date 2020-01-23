/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:06:34 by rgauthie          #+#    #+#             */
/*   Updated: 2019/11/09 18:29:34 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

SDL_Color	int_to_rgb(uint32_t color)
{
	SDL_Color	rgb;

	rgb.a = (color >> 24);
	rgb.r = (color >> 16);
	rgb.g = (color >> 8);
	rgb.b = color;
	return (rgb);
}

SDL_Surface	*get_texte(char *txt, char *font, SDL_Color color, unsigned scale)
{
	SDL_Surface	*texte;
	TTF_Font	*police;

	texte = NULL;
	police = NULL;
	if (!(police = TTF_OpenFont(font, scale)))
		return (NULL);
	if (!(texte = TTF_RenderText_Blended(police, txt, color)))
		return (NULL);
	TTF_CloseFont(police);
	return (texte);
}
