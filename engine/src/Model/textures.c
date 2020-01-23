/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:38:07 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 16:55:47 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

uint32_t	get_pixel(SDL_Surface *surface, float i, float j)
{
	int		x;
	int		y;
	uint8_t	*p;

	x = (int)i % surface->w;
	y = (int)j % surface->h;
	p = (uint8_t *)surface->pixels + y * surface->pitch
		+ x * surface->format->BytesPerPixel;
	return (*(Uint32 *)p);
}
