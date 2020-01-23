/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:27:52 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/14 16:57:00 by rgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static void	projection(t_line *line, int i)
{
	int scaling;

	scaling = (1.0 - line->vect[i][2]) /
		(line->vect[1 - i][2] - line->vect[i][2]);
	line->vect[i][0] += scaling *
		(line->vect[1 - i][0] - line->vect[i][0]);
	line->vect[i][1] += scaling *
		(line->vect[1 - i][1] - line->vect[i][1]);
	line->vect[i][2] = 1.0;
}

void		line_projection(t_core *core, t_line *line)
{
	float	scaling;
	int		i;

	line->visible = 1;
	if ((line->vect[0][2] < 0.0) && (line->vect[1][2] < 0.0))
		line->visible = 0;
	i = 0;
	while (i < 2)
	{
		if (line->vect[i][2] <= 0.0)
			projection(line, i);
		scaling = core->camera.focal / line->vect[i][2];
		line->vect[i][0] *= scaling;
		line->vect[i][1] *= scaling;
		i++;
	}
}
