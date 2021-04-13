/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:37:32 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 14:23:26 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	map_floodfill(t_cubinfo *cubinfo, int x, int y)
{
	if (cubinfo->map[x][y] == '\0')
	{
		dprintf(1, "map invalid.\n");
		//cubinfo_print(cubinfo);
		exit(-1);
	}
	if ((x == 0 || y == 0 || x == cubinfo->map_size[0] - 1 || \
y == cubinfo->map_size[1] - 1) && cubinfo->map[x][y] != '1')
	{
		dprintf(1, "map invalid\n");
		//cubinfo_print(cubinfo);
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

static void	check_colors(int *color, t_cubinfo *cubinfo)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			freestructs_msg(cubinfo, "color not set.");
		if (color[i] < 0 || color[i] > 255)
			freestructs_msg(cubinfo, "invalid color (0 < x < 255).");
		i++;
	}
}

void	data_validator(t_cubinfo *cubinfo)
{
	if (cubinfo->res[0] <= 0 || cubinfo->res[1] <= 0)
		freestructs_msg(cubinfo, "invalid resolution.");
	if (cubinfo->spawn[0] == -1 || cubinfo->spawn[1] == -1)
		freestructs_msg(cubinfo, "map invalid: no spawn.");
	map_floodfill(cubinfo, cubinfo->spawn[0], cubinfo->spawn[1]);
	if (cubinfo->res[0] > 2560)
		cubinfo->res[0] = 2560;
	if (cubinfo->res[1] > 1440)
		cubinfo->res[1] = 1440;
	check_colors(cubinfo->color_ceil, cubinfo);
	check_colors(cubinfo->color_floor, cubinfo);
}
