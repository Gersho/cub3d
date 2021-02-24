/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:16:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/24 13:07:30 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	*mapinfo_setup(t_cubinfo *cubinfo, char *path)
{
//	mapinfo = malloc(sizeof(t_mapinfo));
//	if (!mapinfo)
//		freestructs_exit(NULL, cubinfo, -1);
//	mapinfo->map = NULL;
//	mapinfo->sprite[0] = -1;
//	mapinfo->sprite[1] = -1;
//	mapinfo->spawn[0] = -1;
//	mapinfo->spawn[1] = -1;
//	mapinfo->facing = 0;
	//mapinfo->size[0] = cubinfo->map_size[0];
	//mapinfo->size[1] = cubinfo->map_size[1];
	mapinfo_instantiate(cubinfo);
	mapinfo_fill(cubinfo, path);
	mapinfo_parse(cubinfo);
}

/*
void	mapinfo_init(t_mapinfo *mapinfo)
{
	mapinfo->map = NULL;
	mapinfo->sprite[0] = -1;
	mapinfo->sprite[1] = -1;

	mapinfo->spawn[0] = -1;
	mapinfo->spawn[1] = -1;
	mapinfo->facing = 0;
}
*/

void	mapinfo_instantiate(t_cubinfo *cubinfo)
{
	int	i;

	i = 0;
	cubinfo->map = malloc((cubinfo->map_size[0] + 1)*(sizeof(char*)));
	cubinfo->map[cubinfo->map_size[0]] = NULL;
	while (i < cubinfo->map_size[0])
	{
		cubinfo->map[i] = ft_calloc((cubinfo->map_size[1] + 1), sizeof(char));
		if (cubinfo->map[i] == NULL)
		{
			ft_free_all_2d(cubinfo->map, i - 1);
			//mapinfo_free(mapinfo);
			freestructs_exit(cubinfo, -1);
		}
		i++;
	}
}
/*
void	mapinfo_free(t_mapinfo *mapinfo)
{
	ft_free_all_2d(mapinfo->map, mapinfo->size[0] - 1);
	free(mapinfo);
}
*/
void	mapinfo_fill(t_cubinfo *cubinfo, char *path)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	fd = open(path, O_RDONLY);
	if (!fd)
		freestructs_exit(cubinfo, -1);
	i = -1;
	while (1)
	{
		i++;
		ret = get_next_line(fd, &line);
		if (ret == -1)
			freestructs_exit(cubinfo, -1);
		if (i < cubinfo->map_start)
			continue ;
		ft_memcpy(cubinfo->map[i - cubinfo->map_start], line, ft_strlen(line));
		free(line);
		if (ret == 0)
			break ;
	}
}

void	mapinfo_parse(t_cubinfo *cubinfo)
{
	int	i;
	int	j;

	i = 0;
	while (cubinfo->map[i])
	{
		j = 0;
		while (cubinfo->map[i][j])
		{
			if (cubinfo->map[i][j] == '2')
			{
				cubinfo->sprite[0] = i;
				cubinfo->sprite[1] = j;
			}
			if (ft_str_index_c("NSEW", cubinfo->map[i][j]) != -1)
			{
				if (cubinfo->spawn[0] == -1)
				{
					cubinfo->spawn[0] = i;
					cubinfo->spawn[1] = j;
					cubinfo->facing = cubinfo->map[i][j];
				}
				else
					freestructs_msg(cubinfo, "multiple spawn on map.");
			}
			j++;
		}
		i++;
	}
}
