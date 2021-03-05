/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/05 13:03:25 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_map(t_cubinfo *cubinfo)
{
	t_vars	vars;

	(void) cubinfo;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "kzennoun's cube");
	vars.img = mlx_new_image(vars.mlx, 800, 600);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
	&vars.line_length, &vars.endian);

	int i,j=i=200;
	while (i < 400)
	{
		j = 200;
		while (j < 400)
		{
			my_mlx_pixel_put(&vars, i, j, create_trgb(0,250,250,250));
			j++;
		}
		i++;
	}

	
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
}
