/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:37:32 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/23 10:31:07 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* int	data_validate(t_cubinfo *cubinfo, t_mapinfo *mapinfo)
{

}
 */
void	map_floodfill(t_mapinfo *mapinfo, int x, int y)
{
	// dprintf(1, "---scanning:%d,%d\n", x, y);
	//mapinfo_print(mapinfo);

	if ((x == 0 || y == 0 || x == mapinfo->size[0] - 1 || y == mapinfo->size[1] - 1) && mapinfo->map[x][y] != '1')
	{
		// dprintf(1, "map invalid\n");
		mapinfo_print(mapinfo);
		exit(-1);
	}
	if (ft_str_index_c("1*2", mapinfo->map[x][y]) != -1)
	{
		// dprintf(1, "+++SKIPPING:%d,%d\n", x, y);
		return ;
	}
	if (ft_str_index_c("0 ", mapinfo->map[x][y]) != -1)
		mapinfo->map[x][y] = '*';
	// dprintf(1, "after the ifs\n");


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