/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:01:47 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:31:27 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		vector_transform(float dest[3], float matrix[4][4], float src[3])
{
	int		i;
	int		j;
	float	tmp[3];

	i = 0;
	while (i < 3)
	{
		tmp[i] = 0.0;
		j = 0;
		while (j < 3)
		{
			tmp[i] += matrix[i][j] * src[j];
			j++;
		}
		tmp[i] += matrix[i][3];
		i++;
	}
	vector_cpy(dest, tmp);
}
