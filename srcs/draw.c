/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/13 15:43:26 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mynextframe(t_vars *vars)
{
	t_coord	vect;
	t_trgb	trgb;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	update_pc(vars);
	while (!is_lastsprite(vars->sprites[i]))
	{
		vars->sprites[i].plane = create_sprite_plane(vars, i);
		i++;
	}
	vars->sprites[i].plane = (t_plane){-255, -255, -255, -255};
	j = 0;
	while (j <= vars->cubinfo->res[1])
	{
		i = 0;
		while (i <= vars->cubinfo->res[0])
		{
			vect = get_vector(vars, i, j);
			trgb = pick_pixel_color(vars, vect);
			k = 0;
			my_mlx_pixel_put(&vars->img, i, j, trgb.trgb);
			while (k < vars->upscale)
			{
				l = 0;
				while (l < vars->upscale)
				{
					l++;
					if ((i + l) >= (vars->cubinfo->res[0]) || (j + k) >= (vars->cubinfo->res[1]))
						continue ;
					my_mlx_pixel_put(&vars->img, (i + l), (j + k), trgb.trgb);
				}
				k++;
			}
			i += vars->upscale - 1;
		}
		j += vars->upscale - 1;
	}
	if (vars->savemode == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	else
		img_to_bmp(vars);
	return (0);
}

void	draw_map(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		free_all_exit(vars);
	xpm_setup(vars);
	if (vars->savemode == 0)
	{
		vars->win = mlx_new_window(vars->mlx, vars->cubinfo->res[0], vars->cubinfo->res[1], "kzennoun's cube");
		if (vars->win == NULL)
			free_all_exit(vars);
	}
	vars->img.img = mlx_new_image(vars->mlx, vars->cubinfo->res[0], vars->cubinfo->res[1]);
	if (vars->img.img == NULL)
		free_all_exit(vars);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			 &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_all_exit(vars);
	if (vars->savemode == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		mlx_hook(vars->win, 2, 1L <<0, keydown, vars);
		mlx_hook(vars->win, 3, 1L <<1, keyup, vars);
		mlx_hook(vars->win, 17, 1L <<17, buttons, vars);
	}
	mlx_loop_hook(vars->mlx, mynextframe, vars);
	mlx_loop(vars->mlx);
}
