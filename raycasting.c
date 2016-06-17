/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:58:49 by ghavenga          #+#    #+#             */
/*   Updated: 2016/06/17 10:15:24 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		determine(t_main *gamestate)
{
	t_ray	ray;
	
	init_ray(gamestate, ray);
	while (ray.x < WIN_X)
	{
		cast_ray(&ray, gamestate);
		ray.alpla += gamestate->consts.beta_inc;
		ray.x++;
	}	
}

t_ray		cast_ray(t_ray *ray, t_main *gamestate)
{
	

	DELTADISTX = sqrt(1 + (RAYDIRY * RAYDIRY) / (RAYDIRX * RAYDIRX));
	DELTADISTY = sqrt(1 + (RAYDIRX * RAYDIRX) / (RAYDIRY * RAYDIRY));
}

