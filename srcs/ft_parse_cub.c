/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:23:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/09 11:42:16 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_parse_cf(char *line, t_cubinfo *cubinfo)
{
	int	data[3];
	int	index;

	data[0] = ft_atoi((line + 1));
	index = ft_str_index_c(line + 1, ',') + 1;
	data[1] = ft_atoi(line + 1 + index);
	index += ft_str_index_c(line + 1 + index, ',') + 2;
	data[2] = ft_atoi(line + 1 + index);
	if (line[0] == 'C')
	{
		cubinfo->color_ceil[0] = data[0];
		cubinfo->color_ceil[1] = data[1];
		cubinfo->color_ceil[2] = data[2];
	}
	else
	{
		cubinfo->color_floor[0] = data[0];
		cubinfo->color_floor[1] = data[1];
		cubinfo->color_floor[2] = data[2];
	}
}

void	ft_parse_path(char *line, t_cubinfo *cubinfo)
{
	char	*ptr;

	ptr = ft_strtrim((line + 2), " ");
	if (ptr == NULL)
		freecub_exit(cubinfo, -1);
	if (line[0] == 'S' && line[1] != 'O')
		cubinfo->path_sprite = ptr;
	else if (line[0] == 'N' && line[1] == 'O')
		cubinfo->path_N = ptr;
	else if (line[0] == 'S' && line[1] == 'O')
		cubinfo->path_S = ptr;
	else if (line[0] == 'E' && line[1] == 'A')
		cubinfo->path_E = ptr;
	else if (line[0] == 'W' && line[1] == 'E')
		cubinfo->path_W = ptr;
}

void	ft_parse_r(char *line, t_cubinfo *cubinfo)
{
	char	**ptr;

	ptr = ft_split(line + 1, ' ');
	if (ptr == NULL)
		freecub_exit(cubinfo, -1);
	cubinfo->res[0] = ft_atoi(ptr[0]);
	cubinfo->res[1] = ft_atoi(ptr[1]);
	free(ptr[0]);
	free(ptr[1]);
	free(ptr);
}

int	ft_parse_line(char *line, t_cubinfo *cubinfo)
{
	if (line[0] == 'C' || line[0] == 'F')
		ft_parse_cf(line, cubinfo);
	else if (line[0] == 'R')
		ft_parse_r(line, cubinfo);
	else if (ft_str_index_c("NSWE", (int)line[0]) >= 0)
		ft_parse_path(line, cubinfo);
	else
	{
		cubinfo->map_size[0] += 1;
		if (cubinfo->map_size[1] < ft_strlen(line))
			cubinfo->map_size[1] = ft_strlen(line);
	}
	return (1);
}

int	ft_parse_map(char *path, t_cubinfo *cubinfo)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(path, O_RDONLY);
	if (!fd)
		freecub_exit(cubinfo, -1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			freecub_exit(cubinfo, -1);
		if (ft_strlen(line) == 0)
			continue ;
		ft_parse_line(line, cubinfo);
		if (ret == 0)
			break ;
	}
	//cubinfo_validate
	return (1);
}
