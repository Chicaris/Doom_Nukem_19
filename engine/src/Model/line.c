/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:46 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/18 14:14:12 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

static t_line		*create_line(float v1[3], float v2[3])
{
	t_line	*line;
	int		i;

	i = 0;
	if (!(line = (t_line *)malloc(sizeof(t_line))))
	{
		ft_putstr("Error: malloc (create_line)");
		return (NULL);
	}
	while (i < 3)
	{
		line->vect[0][i] = v1[i];
		line->vect[1][i] = v2[i];
		i++;
	}
	line->visible = 1;
	line->next = NULL;
	return (line);
}

t_line				*init_lines(t_wall wall, float floor, float ceil)
{
	t_line		*tmp;
	t_line		*head;
	float		a[3];
	float		b[3];

	get_vector(a, (float)wall.start[0], (float)wall.start[1], floor);
	get_vector(b, (float)wall.end[0], (float)wall.end[1], floor);
	head = create_line(a, b);
	tmp = head;
	get_vector(a, (float)wall.end[0], (float)wall.end[1], floor);
	get_vector(b, (float)wall.end[0], (float)wall.end[1], ceil);
	tmp->next = create_line(a, b);
	tmp = tmp->next;
	get_vector(a, (float)wall.end[0], (float)wall.end[1], ceil);
	get_vector(b, (float)wall.start[0], (float)wall.start[1], ceil);
	tmp->next = create_line(a, b);
	tmp = tmp->next;
	get_vector(a, (float)wall.start[0], (float)wall.start[1], ceil);
	get_vector(b, (float)wall.start[0], (float)wall.start[1], floor);
	tmp->next = create_line(a, b);
	return (head);
}
