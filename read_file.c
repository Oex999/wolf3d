/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:54:59 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 13:58:35 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	if (!(fd = open(filename, O_RDONLY)))
		ft_puterror("count_lines: Failed to open file");
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (lines);
}

t_mapinfo	read_map(char *filename)
{
	char		*line;
	t_mapinfo	map;
	int			fd;
	int			i;

	i = 0;
	map.lines = 0;
	map.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		ft_puterror("read_map: Failed to open file");
	map.lines = count_lines(filename);
	if (!(map.map = (char **)malloc(sizeof(char *) * map.lines + 1)))
		ft_puterror("read_map: Failed to malloc map.map (char **)");
	while (i < map.lines)
	{
		get_next_line(fd, &line);
		map.map[i++] = line;
	}
	close(fd);
	return (map);
}

void		free_map(t_mapinfo map)
{
	int	l;

	l = 0;
	while (l < map.lines)
	{
		free(map.map[l]);
		l++;
	}
	free(map.map);
}
