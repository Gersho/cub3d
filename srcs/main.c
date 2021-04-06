/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:39:04 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/06 12:30:06 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **argv)
{
	t_vars		vars;
	t_cubinfo	*cubinfo;

	if (!(ac == 2 || ac == 3))
	{
		printf("Error: Wrong number of arguments\n");
		exit (-1);
	}
	if (ac == 3)
	{		
		if (ft_strncmp(argv[2], "--save\0", 7) == 0)
			vars.savemode = 1;
		else
		{
			printf("Error: the only second argument supported is --save\n");
			exit(0);
		}
	}
	else 
		vars.savemode = 0;
	cubinfo = NULL;
	cubinfo = cubinfo_setup(cubinfo, argv[1]);
	mapinfo_setup(cubinfo, argv[1]);
	map_floodfill(cubinfo, cubinfo->spawn[0], cubinfo->spawn[1]);
	cubinfo_print(cubinfo);
	vars_init(cubinfo, &vars);
	draw_map(&vars);

	return (0);
}
