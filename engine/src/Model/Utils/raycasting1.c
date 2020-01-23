/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:28:58 by cbruno            #+#    #+#             */
/*   Updated: 2019/11/15 16:51:10 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/engine.h"

void		get_texture_offset(t_wall *closest_wall, float intersection[3],
		float texture_offset[2], t_sector *sector)
{
	if (closest_wall != NULL)
	{
		if (closest_wall->start[0] != closest_wall->end[0])
			texture_offset[0] = hypotf((intersection[0] -
						closest_wall->start[0]),
					(intersection[1] - closest_wall->start[1]));
		else
			texture_offset[0] = hypotf((intersection[0] - closest_wall->end[0]),
					(intersection[1] - closest_wall->end[1]));
		texture_offset[1] = (sector->ceiling_height - sector->floor_height) -
			(intersection[2] - sector->floor_height);
	}
}

void		get_texture_offset_monster(t_monster *closest_monster,
		float intersection[3], float texture_offset[2])
{
	if (closest_monster != NULL)
	{
		if (closest_monster->start[0] != closest_monster->end[0])
			texture_offset[0] = hypotf((intersection[0] -
						closest_monster->start[0]),
					(intersection[1] - closest_monster->start[1]));
		else
			texture_offset[0] = hypotf((intersection[0] -
						closest_monster->end[0]),
					(intersection[1] - closest_monster->end[1]));
		texture_offset[1] = (closest_monster->ceil -
				closest_monster->floor) -
			(intersection[2] - closest_monster->floor);
	}
}

void		gtop(t_pickup *pickup,
		float intersection[3], float texture_offset[2])
{
	if (pickup != NULL)
	{
		if (pickup->start[0] != pickup->end[0])
			texture_offset[0] = hypotf((intersection[0] - pickup->start[0]),
					(intersection[1] - pickup->start[1]));
		else
			texture_offset[0] = hypotf((intersection[0] - pickup->end[0]),
					(intersection[1] - pickup->end[1]));
		texture_offset[1] = (pickup->ceil - pickup->floor) -
			(intersection[2] - pickup->floor);
	}
}

uint32_t	get_sky_rgb(float ray_dir[3], float texture_offset[3],
		t_sector *sector, t_core *core)
{
	uint32_t	rgb;

	rgb = AMASK;
	if (core->sky_status == DEBUG_FDF_MASK)
	{
		if (get_z_intersection(texture_offset, ray_dir,
					sector->ceiling_height, core->camera.origin) == true)
			rgb = get_pixel(core->level.textures[sector->ceiling_texture],
					texture_offset[0], texture_offset[1]);
	}
	else
	{
		if (get_z_intersection(texture_offset, ray_dir,
					sector->ceiling_height + 10.0 * STEP,
					core->camera.origin) == true)
			rgb = get_pixel(core->level.textures[63],
					texture_offset[0], texture_offset[1]);
	}
	return (rgb);
}
