/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:23:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/08 11:48:53 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_parse_cf(char *line, t_cubinfo *cubinfo)
{
	char	**ptr;
	int	len;
	int	i;
	
	len = 0;
	i = -1;
	while(line[++i])
		if (line[i] == ',')
			len++;
	if (len != 2)
	{
		free(line);
		freestructs_msg(cubinfo, "color(s) not formated properly.");
	}
	len = 0;
	ptr = ft_split(line + 1, ',');
	if (ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
	while(ptr[len] != NULL)
		len++;
	//printf("len: %d\n", len);
	if (len != 3)
	{
		ft_free_all_2d(ptr, len - 1);
		free(line);
		freestructs_msg(cubinfo, "color(s) not formated properly.");
	}
	while(len > 0)
	{
		i = 0;
		while(i < (int)ft_strlen(ptr[len - 1]))
		{
			if (!(ft_isdigit(ptr[len - 1][i]) || ptr[len - 1][i] == ' '))
			{
				ft_free_all_2d(ptr, len - 1);
				free(line);
				freestructs_msg(cubinfo, "color(s) not formated properly.");
			}
			i++;
		}
		
		if (line[0] == 'C')
			cubinfo->color_ceil[len - 1] = ft_atoi(ptr[len - 1]);
		else
			cubinfo->color_floor[len - 1] = ft_atoi(ptr[len - 1]);
		len--;
	}

}

// static void	ft_parse_cf(char *line, t_cubinfo *cubinfo)
// {
// 	int	data[3];
// 	int	index;

// 	data[0] = ft_atoi((line + 1));
// 	index = ft_str_index_c(line + 1, ',') + 1;
// 	data[1] = ft_atoi(line + 1 + index);
// 	index += ft_str_index_c(line + 1 + index, ',') + 2;
// 	data[2] = ft_atoi(line + 1 + index);
// 	if (line[0] == 'C')
// 	{
// 		cubinfo->color_ceil[0] = data[0];
// 		cubinfo->color_ceil[1] = data[1];
// 		cubinfo->color_ceil[2] = data[2];
// 	}
// 	else
// 	{
// 		cubinfo->color_floor[0] = data[0];
// 		cubinfo->color_floor[1] = data[1];
// 		cubinfo->color_floor[2] = data[2];
// 	}
// }

static void	ft_parse_path(char *line, t_cubinfo *cubinfo)
{
	char	*ptr;

	ptr = ft_strtrim((line + 2), " ");
	if (ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
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

static void	ft_parse_r(char *line, t_cubinfo *cubinfo)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = ft_split(line + 1, ' ');
	if (ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
	i = 0;
	while (ptr[i])
	{
		j = 0;
		while(j < (int)ft_strlen(ptr[i]))
		{
			if (!(ft_isdigit(ptr[i][j]) || ptr[i][j] == ' '))
			{
				free(ptr[0]);
				free(ptr[1]);
				free(ptr);
				free(line);
				freestructs_msg(cubinfo, "resolution not formated properly.");
			}
			j++;
		}

		i++;
	}
	if (i != 2)
	{
		ft_free_all_2d(ptr, i - 1);
		free(line);
		freestructs_msg(cubinfo, "resolution not formated properly.");
	}
	cubinfo->res[0] = ft_atoi(ptr[0]);
	cubinfo->res[1] = ft_atoi(ptr[1]);
	free(ptr[0]);
	free(ptr[1]);
	free(ptr);
}

static void	ft_parse_line(char *line, t_cubinfo *cubinfo, int i)
{
	if (ft_strlen(line) == 0)
	{
		if (cubinfo->map_start != -1)
		{
			free(line);
			freestructs_msg(cubinfo, "empty line inside map.");
		}
		else
			return ;
	}
	if (line[0] == 'C' || line[0] == 'F')
		ft_parse_cf(line, cubinfo);
	else if (line[0] == 'R')
		ft_parse_r(line, cubinfo);
	else if (ft_str_index_c("NSWE", (int)line[0]) >= 0)
		ft_parse_path(line, cubinfo);
	else
	{
		if (cubinfo->map_start == -1)
			cubinfo->map_start = i;
		cubinfo->map_size[0] += 1;
		if (cubinfo->map_size[1] < (int)ft_strlen(line))
			cubinfo->map_size[1] = ft_strlen(line);
	}
}

void	ft_parse_map(char *path, t_cubinfo *cubinfo)
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
