/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:23:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/06 13:24:13 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int ft_parse_line(char *line, t_cubinfo *cubinfo)
{

	if (line[0] == 'C')
	{
		//exit? //malloc
	}
	else if(line[0] == 'F')
	{

	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		cubinfo->path_sprite = ft_strtrim((line + 1), " ");
		if (cubinfo->path_sprite == NULL)
			//error handle
	}
	else if (line[0] == 'R')
	{

	}
	else if (ft_str_index_c("NSWE", (int)line[0]) >= 0)
	{

	}

	//else mapdata ?

	return (1);
}

int	ft_parse_map(char *path, t_cubinfo *cubinfo)
{
	int	fd;
	char	*line;


	fd = open(path, O_RDONLY);

	while (get_next_line(fd, &line) >= 1)
	{
		if (ft_strlen(line) == 0)
			continue ;
		if (ft_str_index_c("NSWECFR", (int)line[0]) >= 0)
			ft_parse_line(line, cubinfo);
		//if (!is_valid)
			
			//error handling

	}
	//cubinfo_validate
	return (1);
}
