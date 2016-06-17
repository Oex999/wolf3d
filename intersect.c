/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:12:40 by oexall            #+#    #+#             */
/*   Updated: 2016/06/16 15:07:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_intersect(t_point *p, t_mapinfo *map)
{
	int	r_xg;
	int	r_yg;

	r_xg = p->x / TILE_SIZE;
	r_yg = p->y / TILE_SIZE;
	if (ft_atoi(ft_strsplit(map->map[r_yg], '.')[r_xg]) > 0)
		return (1);
	return (0);
}
