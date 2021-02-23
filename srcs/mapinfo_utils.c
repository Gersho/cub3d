/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:16:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/23 10:29:30 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mapinfo	*mapinfo_setup(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path)
{
	mapinfo = malloc(sizeof(t_mapinfo));
	if (!mapinfo)
		freestructs_exit(NULL, cubinfo, -1);
	mapinfo->map = NULL;
	mapinfo->size[0] = cubinfo->map_size[0];
	mapinfo->size[1] = cubinfo->map_size[1];
	mapinfo_instantiate(mapinfo, cubinfo);
	mapinfo_fill(mapinfo, cubinfo, path);
	mapinfo_parse(mapinfo);
	return (mapinfo);
}

void	mapinfo_instantiate(t_mapinfo *mapinfo, t_cubinfo *cubinfo)
{
	int	i;

	i = 0;
	mapinfo->map = malloc((mapinfo->size[0] + 1)*(sizeof(char*)));
	mapinfo->map[mapinfo->size[0]] = NULL;
	while (i < mapinfo->size[0])
	{
		mapinfo->map[i] = malloc((mapinfo->size[1] + 1)*(sizeof(char)));
		if (mapinfo->map[i] == NULL)
		{
			mapinfo_free(mapinfo);
			freestructs_exit(NULL, cubinfo, -1);
		}
		i++;
	}
}

void	mapinfo_free(t_mapinfo *mapinfo)
{
	ft_free_all_2d(mapinfo->map, mapinfo->size[0] - 1);
	free(mapinfo);
}

void	mapinfo_fill(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	fd = open(path, O_RDONLY);
	if (!fd)
		freestructs_exit(mapinfo, cubinfo, -1);
	i = -1;
	while (1)
	{
		i++;
		ret = get_next_line(fd, &line);
		if (ret == -1)
			freestructs_exit(mapinfo, cubinfo, -1);
		if (i < cubinfo->map_start)
			continue ;
		mapinfo->map[i - cubinfo->map_start] = line;
		//fill la fin de la ligne avec des espaces, finir par /0
		while ()
		{
			
		}
		if (ret == 0)
			break ;
	}
}

void	mapinfo_parse(t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	while (mapinfo->map[i])
	{
		j = 0;
		while (mapinfo->map[i][j])
		{
			if (mapinfo->map[i][j] == '2')
			{
				mapinfo->sprite[0] = i;
				mapinfo->sprite[1] = j;
			}
			if (ft_str_index_c("NSEW", mapinfo->map[i][j]) != -1)
			{
				mapinfo->spawn[0] = i;
				mapinfo->spawn[1] = j;
				mapinfo->facing = mapinfo->map[i][j];
			}
			j++;
		}
		i++;
	}
}
