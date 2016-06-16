/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:27:29 by oexall            #+#    #+#             */
/*   Updated: 2016/06/16 10:49:39 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_sky(t_point *p1, t_win *win)
{
	int	y;

	y = p1->y;
	while (y > 0)
	{
		mlx_pixel_put(win->mlx, win->win, p1->x, y, C_SKY);
		y--;
	}
}

void	draw_wall(t_point *p1, t_point *p2, int color, t_win *win)
{
	int	y1;
	int	y2;

	y1 = p1->y;
	y2 = p2->y;
	while (y1 <= y2)
	{
		mlx_pixel_put(win->mlx, win->win, p1->x, y1, color);
		y1++;
	}
}

void	draw_floor(t_point *p2, t_win *win)
{
	int	y2;

	y2 = p2->y;
	while (y2 <= WIN_Y)
	{
		mlx_pixel_put(win->mlx, win->win, p2->x, y2, C_FLOOR);
		y2++;
	}
}

void	draw(t_point *p1, t_point *p2, int color, t_win *win)
{
	if (p1->x == p2->x)
	{
		draw_sky(p1, win);
		draw_wall(p1, p2, color, win);
		draw_floor(p2, win);
	}
}
