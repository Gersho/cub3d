/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:37:32 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/21 15:13:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* int	data_validate(t_cubinfo *cubinfo, t_mapinfo *mapinfo)
{

}
 */
int	map_floodfill(t_mapinfo *mapinfo, int x, int y, int *isvalid)
{
	printf("scanning:%d,%d\n", x, y);

	if (x == 0 || y == 0 || x == mapinfo->size[0] - 1 || y == mapinfo->size[1] - 1)
		{
			*isvalid = -1;
			return (- 1);
		}
	if (ft_str_index_c("1*2", mapinfo->map[x][y]) != -1)
		return (1);
	if (ft_str_index_c("0 ", mapinfo->map[x][y]) != -1)
		mapinfo->map[x][y] = '*';
	printf("after the ifs\n");


	map_floodfill(mapinfo, x - 1, y - 1, isvalid);
	map_floodfill(mapinfo, x - 1, y, isvalid);
	map_floodfill(mapinfo, x - 1, y + 1, isvalid);
	map_floodfill(mapinfo, x, y - 1, isvalid);
	map_floodfill(mapinfo, x, y + 1, isvalid);
	map_floodfill(mapinfo, x + 1, y - 1, isvalid);
	map_floodfill(mapinfo, x + 1, y, isvalid);
	map_floodfill(mapinfo, x + 1, y + 1, isvalid);

	
	// if (map_floodfill(mapinfo, x - 1, y - 1) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x - 1, y) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x - 1, y + 1) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x, y - 1) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x, y + 1) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x + 1, y - 1) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x + 1, y) == -1)
	// 	return (-1);
	// if (map_floodfill(mapinfo, x + 1, y + 1) == -1)
	// 	return (-1);
	return (1);
}