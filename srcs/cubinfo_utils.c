/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:46:12 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/09 16:14:13 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*
int		cubinfo_validate(t_cubinfo *cubinfo)
{
	//a refaire, cdlamerde
	if (!cubinfo->path_N || !cubinfo->path_S || !cubinfo->path_E
	 ||!cubinfo->path_W || !cubinfo->path_sprite)
	 	return (0);
	if (!cubinfo->res[0] || !cubinfo->res[1] || !cubinfo->color_floor[0] 
	|| !cubinfo->color_floor[1] || !cubinfo->color_floor[2] 
	|| !cubinfo->color_ceil[0] || !cubinfo->color_ceil[1] 
	|| !cubinfo->color_ceil[2])
		return (0);
	if (cubinfo->map_size[0] == 0 || cubinfo->map_size[1] == 0)
		return (0);
	return (1);
}
*/

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
	cubinfo->map_size[0] = 0;
	cubinfo->map_size[1] = 0;
}

void	cubinfo_free(t_cubinfo *cubinfo)
{
	if (cubinfo->path_N)
		free(cubinfo->path_N);
	if (cubinfo->path_S)
		free(cubinfo->path_S);
	if (cubinfo->path_E)
		free(cubinfo->path_E);
	if (cubinfo->path_W)
		free(cubinfo->path_W);
	if (cubinfo->path_sprite)
		free(cubinfo->path_sprite);
	free(cubinfo);
}

void cubinfo_print(t_cubinfo *cubinfo)
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
	printf("Path_N:%s\n",cubinfo->path_N);
	printf("Path_S:%s\n",cubinfo->path_S);
	printf("Path_E:%s\n",cubinfo->path_E);
	printf("Path_W:%s\n",cubinfo->path_W);
	printf("Path_sprite:%s\n",cubinfo->path_sprite);
}
