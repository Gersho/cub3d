/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:39:04 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/21 16:54:37 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **argv)
{
	t_cubinfo	*cubinfo;
	t_mapinfo	*mapinfo;

	if (ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit (-1);
	}
	cubinfo = cubinfo_setup(cubinfo, argv[1]);
	//cubinfo_print(cubinfo);
	mapinfo = mapinfo_setup(mapinfo, cubinfo, argv[1]);
	mapinfo_print(mapinfo);
	map_floodfill(mapinfo, mapinfo->spawn[0], mapinfo->spawn[1]);
	// if (result == 1)
	// 	printf("map test: OK\n");
	// else 
	// 	printf("map not valid\n");

	//printf("result:%d\n", *result);
	printf("map is OK\n");
	mapinfo_print(mapinfo);
	return (0);
}
