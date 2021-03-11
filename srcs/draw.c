/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/11 14:12:10 by kzennoun         ###   ########lyon.fr   */
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

t_coord	intersection(t_vect vect, t_coord pos, t_plane plane)
{
	float       t;
	t_coord     res;
	
	if ((vect.x * plane.a + vect.y * plane.b + vect.z * plane.c) == 0)
	{
		res.x = -1;
		res.y = -1;
		res.z = -1;
		return (res);
	}
	t = -(plane.a * pos.x + plane.b * pos.y + plane.c * pos.z + plane.d) /
	(vect.x * plane.a + vect.y * plane.b + vect.z * plane.c);
	res.x = pos.x + t * vect.x;
	res.y = pos.y + t * vect.y;
	res.z = pos.z + t * vect.z;
	printf("t:%f\n", t);
	return (res);
}

int mynextframe(t_vars *vars)
{
	//my_mlx_pixel_put(&vars->img, x, y, vars->img.trgb.trgb);


	t_plane p1;
	t_plane p2;
	t_plane p3;
	t_plane p4;
	//char	*p;
	//t_coord	pos;
	//t_coord	res;
	//t_vect	vect;
	int	i,j=i=0;

	// vect.x = 0;
	// vect.y = -1;
	// vect.z = 0;

	// vars->img.trgb.t = 0;
	// vars->img.trgb.r = 255;
	// vars->img.trgb.g = 255;
	// vars->img.trgb.b = 255;
	// pos.x = 2.5;
	// pos.y = 2.5;
	// pos.z = 0.5;
	p1.a = 0;
	p1.b = 1;
	p1.c = 0;
	p1.d = -1;
	p2.a = 0;
	p2.b = 1;
	p2.c = 0;
	p2.d = -4;
	p3.a = 1;
	p3.b = 0;
	p3.c = 0;
	p3.d = -1;
	p4.a = 1;
	p4.b = 0;
	p4.c = 0;
	p4.d = -4;

	

	while (j <= vars->cubinfo->res[1])
	{
		i = 0;
		while (i <= vars->cubinfo->res[0])
		{
			// printf("--------\n");
			// printf("i:%d -- j:%d\n",i ,j );
			// vect = get_vector(cubinfo, i, j);
			// res = intersection(vect, vars.pc.pos, p1);
			// printf("vect.x:%f\n", vect.x);
			// printf("vect.y:%f\n", vect.y);
			// printf("vect.z:%f\n", vect.z);
			// coord_print(res);

			
			i++;
		}

		j++;
	}
	//vect = get_vector(cubinfo);


	
	// printf("p1\n");
	// printf("p1.a:%f\n", p1.a);
	// printf("p1.b:%f\n", p1.b);
	// printf("p1.c:%f\n", p1.c);
	// printf("p1.d:%f\n", p1.d);
	// res = intersection(vect, pos, p1);
	// coord_print(res);
	// printf("p2\n");
	// printf("p2.a:%f\n", p2.a);
	// printf("p2.b:%f\n", p2.b);
	// printf("p2.c:%f\n", p2.c);
	// printf("p2.d:%f\n", p2.d);
	// res = intersection(vect, pos, p2);
	// coord_print(res);
	// printf("p3\n");
	// printf("p3.a:%f\n", p3.a);
	// printf("p3.b:%f\n", p3.b);
	// printf("p3.c:%f\n", p3.c);
	// printf("p3.d:%f\n", p3.d);
	// res = intersection(vect, pos, p3);
	// coord_print(res);
	// printf("p4\n");
	// printf("p4.a:%f\n", p4.a);
	// printf("p4.b:%f\n", p4.b);
	// printf("p4.c:%f\n", p4.c);
	// printf("p4.d:%f\n", p4.d);
	// res = intersection(vect, pos, p4);
	// coord_print(res);

	//exit(0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

	// char	*p;
	// mlx_string_put(vars->mlx, vars->win, 220, 420, vars->img.trgb.trgb, "X");
    // p = ft_itoa(vars->pc.pos.x * 100);
    // mlx_string_put(vars->mlx, vars->win, 220, 440, vars->img.trgb.trgb, p);
    // free(p);
    // mlx_string_put(vars->mlx, vars->win, 270, 420, vars->img.trgb.trgb, "Y");
    // p = ft_itoa(vars->pc.pos.y * 100);
    // mlx_string_put(vars->mlx, vars->win, 270, 440, vars->img.trgb.trgb, p);
    // free(p);
    // mlx_string_put(vars->mlx, vars->win, 320, 420, vars->img.trgb.trgb, "Z");
    // p = ft_itoa(vars->pc.pos.z * 100);
    // mlx_string_put(vars->mlx, vars->win, 320, 440, vars->img.trgb.trgb, p);
    // free(p);


	return (0);
}

t_vect	get_vector(t_cubinfo *cubinfo, int i, int j)
{
	t_vect	vect;
	double	s;
	double		fov;

	fov = 11.52;
	s = 2 * tan(fov / 2);
	vect.x = (i - (cubinfo->res[0] / 2)) * (s / cubinfo->res[0]);
	vect.y = -1;
	vect.z = (j - (cubinfo->res[1] / 2)) * (s / cubinfo->res[1]);

	return (vect);
}

void	draw_map(t_cubinfo *cubinfo)
{
	t_vars	vars;

	vars.cubinfo = cubinfo;
	vars.pc.pos.x = 2.5;
	vars.pc.pos.y = 2.5;
	vars.pc.pos.z = 0.5;

	vars.img.trgb.t = 0;
	vars.img.trgb.r = vars.img.trgb.g = vars.img.trgb.b = 255;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
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
