/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:53:15 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:31:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		vector_normalize(float vect[3])
{
	float	length;

	length = sqrtf(vect[0] * vect[0] + vect[1] * vect[1] + vect[2] * vect[2]);
	vect[0] = vect[0] / length;
	vect[1] = vect[1] / length;
	vect[2] = vect[2] / length;
}
