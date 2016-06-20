/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:12:40 by oexall            #+#    #+#             */
/*   Updated: 2016/06/17 09:09:27 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		in_bound(int x, int y, t_mapinfo *info)
{
	if (x < 0 || y < 0)
		return (-1);
	if (x > info->width || y > info->lines)
		return (-1);
	return (0);
}

int		is_intersect(t_point *p, t_main *main)
{
	int	xg;
	int	yg;

	xg = p->x / TILE_SIZE;
	yg = p->y / TILE_SIZE;
	if (in_bound(xg - 1, yg - 1, &main->map) && main->array[xg - 1][yg - 1] > 0)
		return (-1);
	if (in_bound(xg, yg - 1, &main->map) && main->array[xg][yg - 1] > 0)
		return (-1);
	if (in_bound(xg + 1, yg - 1, &main->map) && main->array[xg + 1][yg - 1] > 0)
		return (-1);
	if (in_bound(xg + 1, yg, &main->map) && main->array[xg + 1][yg] > 0)
		return (-1);
	if (in_bound(xg + 1, yg + 1, &main->map) && main->array[xg + 1][yg + 1] > 0)
		return (-1);
	if (in_bound(xg, yg + 1, &main->map) && main->array[xg][yg + 1] > 0)
		return (-1);
	if (in_bound(xg - 1, yg + 1, &main->map) && main->array[xg - 1][yg + 1] > 0)
		return (-1);
	if (in_bound(xg - 1, yg, &main->map) && main->array[xg - 1][yg] > 0)
		return (-1);
	return (0);
}
