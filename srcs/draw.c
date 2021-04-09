/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/09 15:22:54 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int mynextframe(t_vars *vars)
{

	t_coord	vect;
	t_trgb	trgb;
	int	i,j=i=0;
	int	upscale;
	int k;
	int l;

	//k = 1;
	upscale = 7;
	update_pc(vars);
	while (!is_lastsprite(vars->sprites[i]))
	{
		vars->sprites[i].plane = create_sprite_plane(vars, i);
		i++;
	}
	vars->sprites[i].plane = (t_plane){-255,-255,-255,-255};
	// i = 0;
	// while (!is_lastsprite(vars->sprites[i]))
	// {
	// 	printf("sprite:%d\n", i);
	// 	coord_print(vars->sprites[i].pos);
	// 	i++;
	// }
	// 		printf("sprite:%d\n", i);
		//coord_print(vars->sprites[i].pos);
	// printf("sprite planes:\n");
	// i = 0;
	// while (!is_lastsprite(vars->sprites[i]))
	// {
	// 	printf("plane %d {%f, %f, %f, %f}\n", i, vars->sprites[i].plane.a, vars->sprites[i].plane.b, vars->sprites[i].plane.c, vars->sprites[i].plane.d);
	// 	coord_print(vars->sprites[i].pos);
	// 	i++;
	// }
	// 			printf("pc coords\n");
	// 	coord_print(vars->pc.pos);
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
			while (k < upscale)
			{
				l = 1;
				while(l < upscale)
				{
					my_mlx_pixel_put(&vars->img, (i + l), (j + k), trgb.trgb);
					l++;
				}
				k++;
			}
			
			i += upscale - 1;
		}
		j += upscale - 1;
	}


	if (vars->savemode == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	else
	{
		//do save stuff
		img_to_bmp(vars);
		exit(0);

	}

	//exit(0);
	// char	*p;
	// mlx_string_put(vars->mlx, vars->win, 220, 120, vars->trgb_text.trgb, "X");
    // p = ft_itoa(vars->pc.pos.x * 100);
    // mlx_string_put(vars->mlx, vars->win, 220, 140, vars->trgb_text.trgb, p);
    // free(p);
    // mlx_string_put(vars->mlx, vars->win, 270, 120, vars->trgb_text.trgb, "Y");
    // p = ft_itoa(vars->pc.pos.y * 100);
    // mlx_string_put(vars->mlx, vars->win, 270, 140, vars->trgb_text.trgb, p);
    // free(p);
    // mlx_string_put(vars->mlx, vars->win, 320, 120, vars->trgb_text.trgb, "Z");
    // p = ft_itoa(vars->pc.pos.z * 100);
    // mlx_string_put(vars->mlx, vars->win, 320, 140, vars->trgb_text.trgb, p);
    // free(p);
	// char abc[10];
	// ftoa(vars->pc.angle, abc, 3);
    // mlx_string_put(vars->mlx, vars->win, 340, 150, vars->trgb_text.trgb, abc);
	// ftoa(vars->pc.head_tilt, abc, 3);
	// mlx_string_put(vars->mlx, vars->win, 360, 170, vars->trgb_text.trgb, abc);
	return (0);
}






// t_coord	get_vector(t_vars *vars, int i, int j)
// {
// 	t_coord	vect;
// 	t_coord tmp;

// 	vect.x = (i - vars->precalc.res0_2) * vars->precalc.r_h;
// 	vect.y = -1;
// 	vect.z = -(j - vars->precalc.res1_2) * vars->precalc.r_v;
// //rot x (HEAD UP/DOWN)
// 	// //tmp.x = vect.x;
// 	// tmp.y = vect.y * (cos(vars->pc.head_tilt)) + (-vect.z * sin(vars->pc.head_tilt));
// 	// tmp.z = vect.y * sin(vars->pc.head_tilt) +  vect.z * cos(vars->pc.head_tilt);
// 	// //vect.x = tmp.x;
// 	// vect.y = tmp.y;
// 	// //vect.z = tmp.z;
// //rot z (HEAD LEFT/RIGHT)
// 	tmp.x = vect.x * cos(vars->pc.angle) + vect.y * (-sin(vars->pc.angle));
// 	tmp.y = vect.x * sin(vars->pc.angle) + vect.y * cos(vars->pc.angle);
// 	tmp.z = vect.z;
	
// 	return (tmp);
// }


int		buttons(t_vars *vars)
{
	normal_shutdown(vars);
	return(0);
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
		if(vars->win == NULL)
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
		mlx_hook(vars->win, 2, 1L<<0, keydown, vars);
		mlx_hook(vars->win, 3, 1L<<1, keyup, vars);
		mlx_hook(vars->win, 17, 1L<<17, buttons,vars);
	}
	mlx_loop_hook(vars->mlx, mynextframe, vars);
	mlx_loop(vars->mlx);
}
