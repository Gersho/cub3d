/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:37:32 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/23 11:28:21 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_floodfill(t_mapinfo *mapinfo, int x, int y)
{
	if (mapinfo->map[x][y] == '\0')
	{
		dprintf(1, "map invalid(met \\0)\n");
		mapinfo_print(mapinfo);
		exit(-1);
	}
	if ((x == 0 || y == 0 || x == mapinfo->size[0] - 1 || y == mapinfo->size[1] - 1) && mapinfo->map[x][y] != '1')
	{
		dprintf(1, "map invalid\n");
		mapinfo_print(mapinfo);
		exit(-1);
	}
	if (ft_str_index_c("1*2", mapinfo->map[x][y]) != -1)
		return ;
	if (ft_str_index_c("0 ", mapinfo->map[x][y]) != -1)
		mapinfo->map[x][y] = '*';
	map_floodfill(mapinfo, x - 1, y - 1);
	map_floodfill(mapinfo, x - 1, y);
	map_floodfill(mapinfo, x - 1, y + 1);
	map_floodfill(mapinfo, x, y - 1);
	map_floodfill(mapinfo, x, y + 1);
	map_floodfill(mapinfo, x + 1, y - 1);
	map_floodfill(mapinfo, x + 1, y);
	map_floodfill(mapinfo, x + 1, y + 1);
	return ;
}
