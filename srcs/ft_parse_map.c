/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:23:37 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/06 10:38:41 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int ft_parse_line(char *line, t_cubinfo *cubinfo)
{
	if (line[0] == 'C' || line[0] == 'F')
	{

	}
	else if (line[0] == 'S' && line[1] != 'O')
	{

	}


	//else check validity

	return (1);
}

int	ft_parse_map(char *path, t_cubinfo *cubinfo)
{
	int	fd;
	char	*line;
	int	is_valid;

	fd = open(path, O_RDONLY);

	while (get_next_line(fd, &line) >= 1)
	{
		is_valid = ft_parse_line(line, cubinfo);
		//if (!is_valid)
			
			//error handling

	}

	return (1);
}
