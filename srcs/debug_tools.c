/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:59:02 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/20 15:05:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cubinfo_print(t_cubinfo *cubinfo)
{
	printf("res:%d,%d\n", cubinfo->res[0], cubinfo->res[1]);
	printf("color_floor:%d,", cubinfo->color_floor[0]);
	printf("%d,", cubinfo->color_floor[1]);
	printf("%d\n", cubinfo->color_floor[2]);
	printf("color_ceil:%d,", cubinfo->color_ceil[0]);
	printf("%d,", cubinfo->color_ceil[1]);
	printf("%d\n", cubinfo->color_ceil[2]);
	printf("map_size:%d,", cubinfo->map_size[0]);
	printf("%d\n", cubinfo->map_size[1]);
	printf("map_start:%d\n", cubinfo->map_start);
	printf("Path_N:%s\n", cubinfo->path_N);
	printf("Path_S:%s\n", cubinfo->path_S);
	printf("Path_E:%s\n", cubinfo->path_E);
	printf("Path_W:%s\n", cubinfo->path_W);
	printf("Path_sprite:%s\n", cubinfo->path_sprite);
}

void	mapinfo_print(t_mapinfo *mapinfo)
{
	printf("sprite:%d,%d\n", mapinfo->sprite[0], mapinfo->sprite[1]);
	printf("spawn:%d,%d\n", mapinfo->spawn[0], mapinfo->spawn[1]);
	printf("size:%d,%d\n", mapinfo->size[0], mapinfo->size[1]);
	printf("facing:%c\n", mapinfo->facing);
	ft_print_char_2d(mapinfo->map);
}
