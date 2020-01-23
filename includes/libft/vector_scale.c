/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:58:10 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 12:58:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		vector_scale(float vect[3], float scale)
{
	vect[0] = vect[0] * scale;
	vect[1] = vect[1] * scale;
	vect[2] = vect[2] * scale;
}