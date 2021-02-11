/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:16:11 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/11 13:52:36 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_mapinfo	*mapinfo_setup(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path)
{
	mapinfo = malloc(sizeof(t_mapinfo));
	if (!mapinfo)
		freecub_exit(cubinfo, -1);
	mapinfo->map == NULL;
	mapinfo->size[0] = cubinfo->map_size[0];
	mapinfo->size[1] = cubinfo->map_size[1];
	mapinfo_instantiate(mapinfo, cubinfo, path);


	return (mapinfo);
}

void	mapinfo_free(t_mapinfo *mapinfo)
{

}

void	mapinfo_instantiate(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path)
{
	int i;

	i = 0;
	mapinfo->map = malloc(mapinfo->size[0] * (sizeof(int*)));

}