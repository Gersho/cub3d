/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:46:12 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/06 11:24:46 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		cubinfo_validate(t_cubinfo *cubinfo)
{

	
}

void	cubinfo_init(t_cubinfo *cubinfo)
{
	cubinfo->res[0] = -1;
	cubinfo->res[1] = -1;
	cubinfo->path_N = NULL;
	cubinfo->path_S = NULL;
	cubinfo->path_E = NULL;
	cubinfo->path_W = NULL;
	cubinfo->path_sprite = NULL;
	cubinfo->color_floor[0] = -1;
	cubinfo->color_floor[1] = -1;
	cubinfo->color_floor[2] = -1;
	cubinfo->color_ceil[0] = -1;
	cubinfo->color_ceil[1] = -1;
	cubinfo->color_ceil[2] = -1;
	cubinfo->map_max_x = -1;
	cubinfo->map_max_y = -1;
}

void	cubinfo_free(t_cubinfo *cubinfo)
{
	free(cubinfo->path_N);
	free(cubinfo->path_S);
	free(cubinfo->path_E);
	free(cubinfo->path_W);
	free(cubinfo->path_sprite);
	free(cubinfo);
}

void cubinfo_debug(t_cubinfo *cubinfo)
{
	printf("res:%d,%d\n", cubinfo->res[0], cubinfo->res[1]);
	printf("Path_N:%s\n",cubinfo->path_N);
	printf("Path_S:%s\n",cubinfo->path_S);
	printf("Path_E:%s\n",cubinfo->path_E);
	printf("Path_W:%s\n",cubinfo->path_W);
	printf("Path_sprite:%s\n",cubinfo->path_sprite);
	printf("color_floor:%d,", cubinfo->color_floor[0]);
	printf("%d,", cubinfo->color_floor[1]);
	printf("%d\n", cubinfo->color_floor[2]);
	printf("color_ceil:%d,\n", cubinfo->color_ceil[0]);
	printf("%d,", cubinfo->color_ceil[1]);
	printf("%d\n", cubinfo->color_ceil[2]);
	printf("map_max_x:%d\n", cubinfo->map_max_x);
	printf("map_max_y:%d\n", cubinfo->map_max_y);
}
