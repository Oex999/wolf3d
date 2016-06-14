/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:58:49 by ghavenga          #+#    #+#             */
/*   Updated: 2016/06/14 08:42:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_screen()
{

	//Draw screen collumn by collumn by determining the players position on the
	//map and the angle they are faceing. 
	//(angle is determined by placing a point in front of the the players x y
	//coordinate that you apply move commands to in the same way they are applied
	//to the player x y, but with the added ability to rotate the additional point
	//using the player xy as an origin point.)
}

/*Works by drawing from the bottom upwards*/
void	draw_collumn(t_win *win, int height, int colour, t_player *s_point)
{
	unsigned int	y_top;
	unsigned int	y_cur;

	y_top = s_point->y - height;
	y_cur = s_point->y;
	while (y_cur >= y_top && y_cur >= 1)
	{
		mlx_pixel_put(win->mlx, win->win, s_point->x, y_cur, colour);
		y_cur--;
	}
}
