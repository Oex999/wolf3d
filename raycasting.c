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

int		raycast(t_main *info)
{
	t_ray	ray;
	
	ray.x = 0;
	while (ray.x < WIN_X)
	{
		
	}	
}

void	draw_screen()
{

	//Draw screen collumn by collumn by determining the players position on the
	//map and the angle they are faceing. 
	//(angle is determined by placing a point in front of the the players x y
	//coordinate that you apply move commands to in the same way they are applied
	//to the player x y, but with the added ability to rotate the additional point
	//using the player xy as an origin point.)
}
