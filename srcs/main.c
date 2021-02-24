/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:39:04 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/24 13:02:03 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **argv)
{
	t_cubinfo	*cubinfo;

	if (ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit (-1);
	}
	cubinfo = cubinfo_setup(cubinfo, argv[1]);
	//cubinfo_print(cubinfo);
	mapinfo_setup(cubinfo, argv[1]);


	cubinfo_print(cubinfo);
	map_floodfill(cubinfo, cubinfo->spawn[0], cubinfo->spawn[1]);

	printf("######map is OK######\n");
	cubinfo_print(cubinfo);


	//freestructs_msg(NULL, cubinfo, "multiple spawns on map");
	return (0);
}
