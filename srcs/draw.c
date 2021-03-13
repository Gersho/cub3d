/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/13 15:34:33 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int myevents(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
	{
		printf("space pressed\n");
	}
	if (keycode == 12)
	{
		printf("Q pressed\n");
	}
	if (keycode == 13)
	{
		printf("W pressed\n");
		vars->pc.pos.y = vars->pc.pos.y - 0.1;
	}

	if (keycode == 14)
	{
		printf("E pressed\n");
	}

	if (keycode == 0)
	{
		printf("A pressed\n");
		vars->pc.pos.x = vars->pc.pos.x - 0.1;
	}

	if (keycode == 1)
	{
		printf("S pressed\n");
		vars->pc.pos.y = vars->pc.pos.y + 0.1;
	}

	if (keycode == 2)
	{
		printf("D pressed\n");
		vars->pc.pos.x = vars->pc.pos.x + 0.1;
	}


	return (0);
}

t_coord	intersection(t_vect vect, t_coord pos, t_plane plane, float *t)
{
	//float       *t;
	t_coord     res;
	
	if ((vect.x * plane.a + vect.y * plane.b + vect.z * plane.c) == 0)
	{
		res.x = -1;
		res.y = -1;
		res.z = -1;
		return (res);
	}
	*t = -(plane.a * pos.x + plane.b * pos.y + plane.c * pos.z + plane.d) /
	(vect.x * plane.a + vect.y * plane.b + vect.z * plane.c);
	res.x = pos.x + *t * vect.x;
	res.y = pos.y + *t * vect.y;
	res.z = pos.z + *t * vect.z;
	//printf("t:%f\n", t);
	return (res);
}

int mynextframe(t_vars *vars)
{

	t_vect	vect;
	t_trgb	trgb;
	int	i,j=i=0;

	

	while (j <= vars->cubinfo->res[1])
	{
		i = 0;
		while (i <= vars->cubinfo->res[0])
		{
			// vect = get_vector(vars->cubinfo, i, j);
			// trgb = pick_pixel_color(vars, vect);
			if (i == 400 && j == 400)
			{
				trgb = vars->trgb_wall_e;
			}
			else 
			{
				vect = get_vector(vars->cubinfo, i, j);
				trgb = pick_pixel_color(vars, vect);
			}

			my_mlx_pixel_put(&vars->img, i, j, trgb.trgb);
			i += 1;
		}
		j += 1;
	}
	//exit(0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	//exit(0);
	char	*p;
	mlx_string_put(vars->mlx, vars->win, 220, 120, vars->trgb_text.trgb, "X");
    p = ft_itoa(vars->pc.pos.x * 100);
    mlx_string_put(vars->mlx, vars->win, 220, 140, vars->trgb_text.trgb, p);
    free(p);
    mlx_string_put(vars->mlx, vars->win, 270, 120, vars->trgb_text.trgb, "Y");
    p = ft_itoa(vars->pc.pos.y * 100);
    mlx_string_put(vars->mlx, vars->win, 270, 140, vars->trgb_text.trgb, p);
    free(p);
    mlx_string_put(vars->mlx, vars->win, 320, 120, vars->trgb_text.trgb, "Z");
    p = ft_itoa(vars->pc.pos.z * 100);
    mlx_string_put(vars->mlx, vars->win, 320, 140, vars->trgb_text.trgb, p);
    free(p);


	return (0);
}

t_vect	get_vector(t_cubinfo *cubinfo, int i, int j)
{
	t_vect	vect;
	double	s;
	double		fov;

	fov = 11.52;
	s = 2 * tan(fov / 2);
	vect.x = -(i - (cubinfo->res[0] / 2)) * (s / cubinfo->res[0]);
	vect.y = -1;
	vect.z = (j - (cubinfo->res[1] / 2)) * (s / cubinfo->res[1]);

	return (vect);
}

void	draw_map(t_cubinfo *cubinfo)
{
	t_vars	vars;

	vars.cubinfo = cubinfo;
	vars.pc.pos.x = 0.5 + cubinfo->spawn[1];
	vars.pc.pos.y = 0.5 + cubinfo->spawn[0];
	vars.pc.pos.z = 0.5;
	
	vars.trgb_floor.t = 0;
	vars.trgb_floor.r = 0;
	vars.trgb_floor.g = 255;
	vars.trgb_floor.b = 0;

	vars.trgb_sky.t = 0;
	vars.trgb_sky.r = 0;
	vars.trgb_sky.g = 0;
	vars.trgb_sky.b = 255;

	// vars.img.trgb.t = 0;
	// vars.img.trgb.r = 255;
	// vars.img.trgb.g = 255;
	// vars.img.trgb.b = 255;

	vars.trgb_wall_e.t = 0;
	vars.trgb_wall_e.r = 255;
	vars.trgb_wall_e.g = 0;
	vars.trgb_wall_e.b = 0;

	vars.trgb_wall.t = 0;
	vars.trgb_wall.r = 255;
	vars.trgb_wall.g = 255;
	vars.trgb_wall.b = 255;

	vars.trgb_text.t = 0;
	vars.trgb_text.r = 0;
	vars.trgb_text.g = 0;
	vars.trgb_text.b = 0;

	vars.img.trgb.t = 0;
	vars.img.trgb.r = vars.img.trgb.g = vars.img.trgb.b = 255;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "kzennoun's cube");
	vars.img.img = mlx_new_image(vars.mlx, 800, 600);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
				 &vars.img.line_length, &vars.img.endian);

   

   //test

   //endtest



	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, myevents, &vars);
	mlx_loop_hook(vars.mlx, mynextframe, &vars);
	mlx_loop(vars.mlx);
}
