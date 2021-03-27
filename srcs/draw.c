/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:30:34 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/27 16:50:05 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_coord	rotate_vect(t_coord vect, float angle)
{
	t_coord tmp;

	tmp.x = vect.x * cos(angle) + vect.y * (-sin(angle));
	tmp.y = vect.x * sin(angle) + vect.y * cos(angle);
	tmp.z = vect.z;

	return (tmp);
}

int myevents(int keycode, t_vars *vars)
{
	//printf("keycode : %d\n", keycode);
	(void) vars;
	if (keycode == 53)
		exit(1);
	if (keycode == 82)
	{
		vars->pc.angle = 0.0;
		vars->pc.pos.x = 0.5 + vars->cubinfo->spawn[1];
		vars->pc.pos.y = 0.5 + vars->cubinfo->spawn[0];
		vars->pc.pos.z = 0.5;
	}
	if (keycode == 49)
	{
		printf("space pressed\n");
	}
	if (keycode == 126)
	{
		vars->pc.head_tilt = vars->pc.head_tilt - 0.05;
	}
	if (keycode == 125)
	{
		vars->pc.head_tilt = vars->pc.head_tilt + 0.05;
	}
	if (keycode == 12)
	{
		vars->pc.angle = vars->pc.angle - 0.05;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	if (keycode == 13)
	{
		vars->pc.pos = move_pc(vars, 1);
	}
	if (keycode == 14)
	{
		vars->pc.angle = vars->pc.angle + 0.05;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	if (keycode == 0)
	{
		vars->pc.angle = vars->pc.angle - M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
		vars->pc.pos = move_pc(vars, 1);
		vars->pc.angle = vars->pc.angle + M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);

	}
	if (keycode == 1)
	{
		vars->pc.pos = move_pc(vars, -1);
	}
	if (keycode == 2)
	{
		vars->pc.angle = vars->pc.angle + M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
		vars->pc.pos = move_pc(vars, 1);
		vars->pc.angle = vars->pc.angle - M_PI_2;
		vars->pc.view = rotate_vect((t_coord){0, -1, 0}, vars->pc.angle);
	}
	return (0);
}

t_coord	intersection(t_coord vect, t_coord pos, t_plane plane, float *t)
{
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
	return (res);
}

int mynextframe(t_vars *vars)
{

	t_coord	vect;
	t_trgb	trgb;
	int	i,j=i=0;

	//vars->sprites->plane = create_sprite_plane(vars);
	while (!is_lastsprite(vars->sprites[i]))
	{
		vars->sprites[i].plane = create_sprite_plane(vars, i);
		printf("sprite[%d] plane:{%f, %f, %f, %f}\n", i, vars->sprites[i].plane.a, vars->sprites[i].plane.b, vars->sprites[i].plane.c, vars->sprites[i].plane.d);
		i++;
	}
	vars->sprites[i].plane = (t_plane){-255,-255,-255,-255};
	printf("sprite[%d] plane:{%f, %f, %f, %f}\n", i, vars->sprites[i].plane.a, vars->sprites[i].plane.b, vars->sprites[i].plane.c, vars->sprites[i].plane.d);
	while (j <= vars->cubinfo->res[1])
	{
		i = 0;
		while (i <= vars->cubinfo->res[0])
		{

			// printf("#########\n");
			// printf("i: %d, j: %d\n", i, j);
			vect = get_vector(vars, i, j);
			trgb = pick_pixel_color(vars, vect);
			// color_print(trgb);
			my_mlx_pixel_put(&vars->img, i, j, trgb.trgb);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	exit(0);
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

t_coord	get_vector(t_vars *vars, int i, int j)
{
	t_coord	vect;
	t_coord tmp;

	vect.x = (i - vars->precalc.res0_2) * vars->precalc.r_h;
	vect.y = -1;
	vect.z = -(j - vars->precalc.res1_2) * vars->precalc.r_v;
//rot x (HEAD UP/DOWN)
	//tmp.x = vect.x;
	tmp.y = vect.y * (cos(vars->pc.head_tilt)) + (-vect.z * sin(vars->pc.head_tilt));
	tmp.z = vect.y * sin(vars->pc.head_tilt) +  vect.z * cos(vars->pc.head_tilt);
	//vect.x = tmp.x;
	vect.y = tmp.y;
	//vect.z = tmp.z;
//rot z (HEAD LEFT/RIGHT)
	tmp.x = vect.x * cos(vars->pc.angle) + vect.y * (-sin(vars->pc.angle));
	tmp.y = vect.x * sin(vars->pc.angle) + vect.y * cos(vars->pc.angle);
	//tmp.z = vect.z;
	
	return (tmp);
}

void	draw_map(t_vars *vars)
{
	vars->mlx = mlx_init();
	xpm_load(vars);
	xpm_getaddr(vars);
	
	vars->win = mlx_new_window(vars->mlx, vars->cubinfo->res[0], vars->cubinfo->res[1], "kzennoun's cube");
	vars->img.img = mlx_new_image(vars->mlx, vars->cubinfo->res[0], vars->cubinfo->res[1]);

	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
				 &vars->img.line_length, &vars->img.endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, 2, 1L<<0, myevents, vars);
	mlx_loop_hook(vars->mlx, mynextframe, vars);
	mlx_loop(vars->mlx);
}
