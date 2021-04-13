/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:16:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 16:26:10 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	mapinfo_instantiate(t_cubinfo *cubinfo)
{
	int	i;

	i = 0;
	cubinfo->map = malloc((cubinfo->map_size[0] + 1) * (sizeof(char *)));
	if (cubinfo->map == NULL)
		freestructs_exit(cubinfo, -1);
	cubinfo->map[cubinfo->map_size[0]] = NULL;
	while (i < cubinfo->map_size[0])
	{
		cubinfo->map[i] = ft_calloc((cubinfo->map_size[1] + 1), sizeof(char));
		if (cubinfo->map[i] == NULL)
		{
			ft_free_all_2d(cubinfo->map, i - 1);
			freestructs_exit(cubinfo, -1);
		}
		i++;
	}
}

static void	mapinfo_fill(t_cubinfo *cubinfo, char *path)
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
		{
			free(line);
			continue ;
		}
		ft_memcpy(cubinfo->map[i - cubinfo->map_start], line, ft_strlen(line));
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
}

static void	mapinfo_parse(t_cubinfo *cubinfo)
{
	int	i;
	int	j;

	i = 0;
	while (cubinfo->map[i])
	{
		j = 0;
		while (cubinfo->map[i][j])
		{
			if (ft_str_index_c("NSEW012 \t\v\n\r\f", cubinfo->map[i][j]) != -1)
			{
				if (cubinfo->map[i][j] == '2')
					cubinfo->sprite_qt = cubinfo->sprite_qt + 1;
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
			}
			j++;
		}
		i++;
	}
}

void	mapinfo_setup(t_cubinfo *cubinfo, char *path)
{
	if (cubinfo->map_size[0] < 1 || cubinfo->map_size[1] < 1)
		freestructs_msg(cubinfo, "map invalid.");
	mapinfo_instantiate(cubinfo);
	mapinfo_fill(cubinfo, path);
	mapinfo_parse(cubinfo);
}
