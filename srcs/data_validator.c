/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:37:32 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/17 15:58:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_floodfill(t_cubinfo *cubinfo, int x, int y)
{
	if (cubinfo->map[x][y] == '\0')
	{
		dprintf(1, "map invalid(met \\0)\n");
		cubinfo_print(cubinfo);
		exit(-1);
	}
	if ((x == 0 || y == 0 || x == cubinfo->map_size[0] - 1 || \
y == cubinfo->map_size[1] - 1) && cubinfo->map[x][y] != '1')
	{
		dprintf(1, "map invalid\n");
		cubinfo_print(cubinfo);
		exit(-1);
	}
	if (ft_str_index_c("1*2", cubinfo->map[x][y]) != -1)
		return ;
	if (ft_str_index_c("0 ", cubinfo->map[x][y]) != -1)
		cubinfo->map[x][y] = '*';
	map_floodfill(cubinfo, x - 1, y - 1);
	map_floodfill(cubinfo, x - 1, y);
	map_floodfill(cubinfo, x - 1, y + 1);
	map_floodfill(cubinfo, x, y - 1);
	map_floodfill(cubinfo, x, y + 1);
	map_floodfill(cubinfo, x + 1, y - 1);
	map_floodfill(cubinfo, x + 1, y);
	map_floodfill(cubinfo, x + 1, y + 1);
}

void	cub_validate(t_cubinfo *cubinfo)
{

	
}
