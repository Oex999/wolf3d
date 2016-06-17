/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 12:45:48 by oexall            #+#    #+#             */
/*   Updated: 2016/06/17 06:59:49 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_get_width(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
			i++;
		line++;
	}
	return (i);
}

void		ft_print_array(int **array, t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("|%d| ", array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int			**get_array(t_mapinfo	*map)
{
	int		**array;
	int		i;
	int		j;

	i = -1;
	map->width = ft_get_width(map->map[0]);	
	if (!(array = (int **)malloc(sizeof(int *) * map->lines)))
		ft_puterror("get_array: Failed to malloc first lvl of array.");
	while (++i < map->width)
		if (!(*(array + i) = (int *)malloc(sizeof(int *) * map->width)))
			ft_puterror("get_array: Failed to malloc second lvl of array");
	i = 0;
	while (i < map->lines)
	{
		j = -1;
		while (++j < map->width)
			array[i][j] = ft_atoi(ft_strsplit(map->map[i], ',')[j]);
		i++;
	}
	ft_print_array(array, map);
	return (array);	
}
