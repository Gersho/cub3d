/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:39:04 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/16 16:01:27 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **argv)
{
	t_vars		vars;
	t_cubinfo	*cubinfo;

	if (ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit (-1);
	}
	cubinfo = NULL;
	cubinfo = cubinfo_setup(cubinfo, argv[1]);
	mapinfo_setup(cubinfo, argv[1]);
	map_floodfill(cubinfo, cubinfo->spawn[0], cubinfo->spawn[1]);
	//printf("######map is OK######\n");
	cubinfo_print(cubinfo);
	vars_init(cubinfo, &vars);
	draw_map(&vars);

	//t_vars	vars;
	// vars.planes = plane_factory(cubinfo);
	// plane_print(vars.planes);

	return (0);
}
