/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:39:04 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/08 13:30:19 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ptr_null_setup(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->planes_x = NULL;
	vars->planes_y = NULL;
	vars->sprites = NULL;
	vars->n_xpm.img = NULL;
	vars->s_xpm.img = NULL;
	vars->e_xpm.img = NULL;
	vars->w_xpm.img = NULL;
	vars->sprite_xpm.img = NULL;
	vars->n_xpm.addr = NULL;
	vars->s_xpm.addr = NULL;
	vars->e_xpm.addr = NULL;
	vars->w_xpm.addr = NULL;
	vars->sprite_xpm.addr = NULL;
	vars->img.img = NULL;
	vars->img.addr = NULL;
}

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
			exit(-1);
		}
	}
	else 
		vars.savemode = 0;
	ptr_null_setup(&vars);
	cubinfo = NULL;
	cubinfo = cubinfo_setup(cubinfo, argv[1]);
	mapinfo_setup(cubinfo, argv[1]);
	map_floodfill(cubinfo, cubinfo->spawn[0], cubinfo->spawn[1]);
	//cubinfo_print(cubinfo);
	//exit(0);
	vars_setup(cubinfo, &vars);
	draw_map(&vars);

	return (0);
}
