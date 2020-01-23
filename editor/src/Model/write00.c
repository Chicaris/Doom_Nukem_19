/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:16:59 by cbruno            #+#    #+#             */
/*   Updated: 2019/10/21 14:17:00 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/editor.h"

t_bool			write_player(t_core *core, int fd)
{
	if (!(write(fd, &core->player->position[0], sizeof(float))))
		return (false);
	if (!(write(fd, &core->player->position[1], sizeof(float))))
		return (false);
	if (!(write(fd, &core->player->position[2], sizeof(float))))
		return (false);
	return (true);
}

t_bool			write_texture_2(int fd, SDL_Surface *texture, unsigned long *bp)
{
	if (!(write(fd, &texture->w, sizeof(int))))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->h, sizeof(int))))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->pitch, sizeof(int))))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->format->BitsPerPixel, 1)))
		return (false);
	*bp += 1;
	if (!(write(fd, &texture->format->Rmask, 4)))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->format->Gmask, 4)))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->format->Bmask, 4)))
		return (false);
	*bp += 4;
	if (!(write(fd, &texture->format->Amask, 4)))
		return (false);
	*bp += 4;
	return (true);
}

t_bool			write_texture(t_core *core, int fd)
{
	SDL_Surface			*texture;
	int					nbr_texture;
	unsigned			i;
	unsigned long		bp;

	nbr_texture = NUM_TEXTURES;
	i = 0;
	if (!(write(fd, &nbr_texture, sizeof(int))))
		return (false);
	bp = sizeof(int);
	while (i < NUM_TEXTURES)
	{
		texture = core->textures[i];
		SDL_LockSurface(texture);
		if (write_texture_2(fd, texture, &bp) == false)
			return (false);
		if ((bp + texture->pitch * texture->h) >= ULONG_MAX)
			return (false);
		if (!(write(fd, texture->pixels, texture->pitch * texture->h)))
			return (false);
		SDL_UnlockSurface(texture);
		i++;
	}
	return (true);
}

t_bool			write_sector_list(t_core *core, int fd)
{
	t_sector_lst	*current;
	int				nbr_sector;

	current = core->sector_list;
	nbr_sector = get_nbr_sector(current, 0);
	if (!(write(fd, &nbr_sector, sizeof(int))))
		return (false);
	while (current != NULL)
	{
		if (!(write(fd, &current->sector->start_wall, sizeof(unsigned))))
			return (false);
		if (!(write(fd, &current->sector->num_walls, sizeof(unsigned))))
			return (false);
		if (!(write(fd, &current->sector->floor_height, sizeof(float))))
			return (false);
		if (!(write(fd, &current->sector->ceiling_height, sizeof(float))))
			return (false);
		if (!(write(fd, &current->sector->floor_texture, sizeof(unsigned))))
			return (false);
		if (!(write(fd, &current->sector->ceiling_texture, sizeof(unsigned))))
			return (false);
		current = current->next;
	}
	return (true);
}

t_bool			write_monster_list_2(int fd, t_monster_lst *current)
{
	if (!(write(fd, &current->monster->texture, sizeof(unsigned))))
		return (false);
	if (!(write(fd, &current->monster->sector_idx, sizeof(int))))
		return (false);
	if (!(write(fd, &current->monster->start[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->start[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->start[2], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->end[0], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->end[1], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->end[2], sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->ceil, sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->floor, sizeof(float))))
		return (false);
	if (!(write(fd, &current->monster->origin[0], sizeof(float))))
		return (false);
	return (true);
}
