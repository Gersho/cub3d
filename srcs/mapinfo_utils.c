/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:16:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/19 14:53:51 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mapinfo	*mapinfo_setup(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path)
{
	mapinfo = malloc(sizeof(t_mapinfo));
	if (!mapinfo)
		freecub_exit(cubinfo, -1);
	mapinfo->map = NULL;
	mapinfo->size[0] = cubinfo->map_size[0];
	mapinfo->size[1] = cubinfo->map_size[1];
	mapinfo_instantiate(mapinfo, cubinfo);
	return (mapinfo);
}

void	mapinfo_instantiate(t_mapinfo *mapinfo, t_cubinfo *cubinfo)
{
	int i;

	i = 0;
	mapinfo->map = malloc(mapinfo->size[0] * (sizeof(char*)));
	while (i < mapinfo->size[0])
	{
		mapinfo->map[i] = malloc((mapinfo->size[1] + 1) * (sizeof(char)));
		if (mapinfo->map[i] == NULL)
		{
			mapinfo_free(mapinfo);
			freecub_exit(cubinfo, -1);
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

	i = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
	{
		mapinfo_free(mapinfo);
		freecub_exit(cubinfo, -1);
	}
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{	
			mapinfo_free(mapinfo);
			freecub_exit(cubinfo, -1);
		}
		if (ret == 0)
			break ;
		if (i < cubinfo->map_start)
			continue ;
		


		i++;
	}

}

void	mapinfo_print(t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapinfo->size[0])
	{
		j = 0;
		while (j < mapinfo->size[1])
		{
			write(1, &mapinfo->map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}