/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:58:49 by ghavenga          #+#    #+#             */
/*   Updated: 2016/06/16 10:56:26 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		cast_ray(t_main *info, t_ray *ray)
{
	ray->ax = info->player.x + (info.player->player.y) / tan(ray->alpla);
	//A.x = Px + (Py-A.y)/tan(ALPHA);
	if (info->player.a > 180)
		ay = floor(info.player->player.y / TILE_SIZE) * TILE_SIZE + 64;
	else
		ay = floor(info.player->player.y / TILE_SIZE) * TILE_SIZE - 1;
	if (info->>player.a > 180)
}

int		init_ray(t_main *info, t_ray *ray)
{
	ray->x = 0;
	ray->alpla = info->player.a - info->consts.half_fov;
}

int		raycast(t_main *info)
{
	t_ray	ray;
	
	init_ray(info, ray);
	while (ray.x < WIN_X)
	{
		cast_ray(&ray, info);
		ray.alpla += info->consts.beta_inc;
		ray.x++;
	}	
}
