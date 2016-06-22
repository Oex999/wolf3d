/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:58:49 by ghavenga          #+#    #+#             */
/*   Updated: 2016/06/20 15:53:46 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		initray(t_main *gamestate, int x)
{
	gamestate->ray.camera = 2 * x / (double)(WIN_X) - 1;
	e->r.pos.x = e->player.pos.x;
	e->r.pos.y = e->player.pos.y;
	RAYDIRX = e->player.dir.x + e->r.plane.x * e->player.camera;
	RAYDIRY = e->player.dir.y + e->r.plane.y * e->player.camera;
	e->r.posmap.x = (int)e->r.pos.x;
	e->r.posmap.y = (int)e->r.pos.y;
	DELTADISTX = sqrt(1 + (RAYDIRY * RAYDIRY) / (RAYDIRX * RAYDIRX));
	DELTADISTY = sqrt(1 + (RAYDIRX * RAYDIRX) / (RAYDIRY * RAYDIRY));
	e->player.hit = 0;
}

static void		raydir(t_main *gamestate)
{
	if (e->r.dir.x < 0)
	{
		e->player.step.x = -1;
		e->r.sidedist.x = (e->r.pos.x - e->r.posmap.x) * e->r.disd.x;
	}
	else
	{
		e->player.step.x = 1;
		e->r.sidedist.x = (e->r.posmap.x + 1.0 - e->r.pos.x) * e->r.disd.x;
	}
	if (e->r.dir.y < 0)
	{
		e->player.step.y = -1;
		e->r.sidedist.y = (e->r.pos.y - e->r.posmap.y) * e->r.disd.y;
	}
	else
	{
		e->player.step.y = 1;
		e->r.sidedist.y = (e->r.posmap.y + 1.0 - e->r.pos.y) * e->r.disd.y;
	}
}

static void		dda(t_main *gamestate)
{
	while (e->player.hit == 0)
	{
		if (e->r.sidedist.x < e->r.sidedist.y)
		{
			e->r.sidedist.x += e->r.disd.x;
			e->r.posmap.x += e->player.step.x;
			e->player.wallside = 0;
		}
		else
		{
			e->r.sidedist.y += e->r.disd.y;
			e->r.posmap.y += e->player.step.y;
			e->player.wallside = 1;
		}
		if (e->map.map[e->r.posmap.x][e->r.posmap.y] > 0)
			e->player.hit = 1;
	}
}

static void		compute(t_main *gamestate)
{
	double distwall;

	if (e->player.wallside == 0)
		distwall = fabs((e->r.posmap.x - e->r.pos.x
					+ (1 - e->player.step.x) / 2) / e->r.dir.x);
	else
		distwall = fabs((e->r.posmap.y - e->r.pos.y
					+ (1 - e->player.step.y) / 2) / e->r.dir.y);
	e->r.lheight = abs((int)(WIN_Y / distwall));
	e->r.ystart = (-1 * (e->r.lheight)) / 2 + WIN_Y / 2;
	if (e->r.ystart < 0)
		e->r.ystart = 0;
	e->r.yend = e->r.lheight / 2 + WIN_Y / 2;
	if (e->r.yend >= WIN_Y)
		e->r.yend = WIN_Y - 1;
}

int				loop_hook(t_main *gamestate)
{
	t_rgb	c;
	int		x;

	if (e->img.img != NULL)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		e->img.img = NULL;
	}
	e->img.img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	x = 0;
	while (x < WIN_X)
	{
		initray(e, x);
		raydir(e);
		dda(e);
		compute(e);
		colors(e, &c);
		drawline(x, e, &c);
		x++;
	}
	get_timeframe(e);
	move(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}
