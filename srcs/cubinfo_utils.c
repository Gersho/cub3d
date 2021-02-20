/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:46:12 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/20 15:48:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_cubinfo	*cubinfo_setup(t_cubinfo *cubinfo, char *path)
{
	cubinfo = malloc(sizeof(t_cubinfo));
	if (!cubinfo)
		error_exit(-1);
	cubinfo_init(cubinfo);
	ft_parse_map(path, cubinfo);
	return (cubinfo);
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
	cubinfo->map_size[0] = 0;
	cubinfo->map_size[1] = 0;
	cubinfo->map_start = -1;
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
