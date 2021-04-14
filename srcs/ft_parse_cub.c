/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:23:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/14 16:23:27 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_prechecks(char *line, t_cubinfo *cubinfo)
{
	if (cubinfo->map_start != -1)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			freestructs_msg(cubinfo, "map is invalid.");
		}
		cubinfo->map_size[0] += 1;
		if (cubinfo->map_size[1] < (int)ft_strlen(line))
			cubinfo->map_size[1] = ft_strlen(line);
		return (1);
	}
	return (0);
}

static void	ft_parse_line(char *line, t_cubinfo *cubinfo, int i)
{
	if (ft_prechecks(line, cubinfo) == 1)
		return ;
	if (ft_strlen(line) == 0)
		return ;
	if (line[0] == 'C' || line[0] == 'F')
		ft_parse_cf(line, cubinfo);
	else if (line[0] == 'R')
		ft_parse_r(line, cubinfo);
	else if (ft_str_index_c("NSWE", (int)line[0]) >= 0)
		ft_parse_path(line, cubinfo);
	else if (ft_str_index_c("NSWE012", (int)line[0]) >= 0)
	{
		cubinfo->map_start = i;
		cubinfo->map_size[0] += 1;
		if (cubinfo->map_size[1] < (int)ft_strlen(line))
			cubinfo->map_size[1] = ft_strlen(line);
	}
	else
	{
		free(line);
		freestructs_msg(cubinfo, "invalid option.");
	}
}

void	ft_parse_cub(char *path, t_cubinfo *cubinfo)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		freestructs_exit(cubinfo, -1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			freestructs_exit(cubinfo, -1);
		ft_parse_line(line, cubinfo, i);
		free(line);
		if (ret == 0)
			break ;
		i++;
	}
	close(fd);
}
