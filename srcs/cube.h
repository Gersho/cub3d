/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/31 14:08:59 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "../libs/minilibx_opengl_20191021/mlx.h"
//# include "../libs/minilibx_mms_20200219/mlx.h"
# include <stdio.h>
# include <math.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int         img_width;
    int         img_height;
}               t_data;

typedef	struct	s_plane
{
	float	a;
	float	b;
	float	c;
	float	d;
}				t_plane;

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef	struct s_sprite
{
	t_plane	plane;
	t_coord	pos;
	//t_data	xpm;
}				t_sprite;

typedef struct s_cubinfo
{
	char	*path_N;
	char	*path_S;
	char	*path_E;
	char	*path_W;
	char	*path_sprite;
	char	**map;
	int		sprite_qt;
	int		spawn[2];
	char	facing;
	int		res[2];
	int		color_floor[3];
	int		color_ceil[3];
	int		map_size[2];
	int		map_start;
}				t_cubinfo;

typedef union	u_trgb
{
	int			trgb;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	t;
	};
	
}				t_trgb;

typedef	struct	s_pc
{
	t_coord		pos;
	t_coord		view;
	float		head_tilt;
	float		angle;
}				t_pc;

typedef struct s_precalc
{
	float		r_h;
	float		r_v;
	int			res0_2;
	int			res1_2;
}				t_precalc;

typedef struct s_keys
{
	uint8_t		up;
	uint8_t		down;
	uint8_t		left;
	uint8_t		right;
	uint8_t		turn_l;
	uint8_t		turn_r;

}				t_keys;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	t_precalc	precalc;
    t_data      img;
	t_data		n_xpm;
	t_data		s_xpm;
	t_data		e_xpm;
	t_data		w_xpm;
	t_data		sprite_xpm;
	t_cubinfo	*cubinfo;
	t_pc		pc;
	t_trgb      trgb_sky;
	t_trgb      trgb_floor;
	t_trgb      trgb_text;
	t_plane		*planes;
	t_plane		*planes_x;
	t_plane		*planes_y;
	t_plane		plane_sky;
	t_plane		plane_floor;
	t_sprite	*sprites;
	t_keys		keys;
}               t_vars;


char		*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size);
char		*ft_gnl_join(char *stock, char *s2, int size);
void		ft_parse_map(char *path, t_cubinfo *cubinfo);
void		cubinfo_free(t_cubinfo *cubinfo);
void		cubinfo_print(t_cubinfo *cubinfo);
void		cubinfo_init(t_cubinfo *cubinfo);
t_cubinfo	*cubinfo_setup(t_cubinfo *cubinfo, char *path);
void		mapinfo_setup(t_cubinfo *cubinfo, char *path);
void		error_exit(int err);
void		mapinfo_instantiate(t_cubinfo *cubinfo);
void		mapinfo_fill(t_cubinfo *cubinfo, char *path);
void		mapinfo_parse(t_cubinfo *cubinfo);
void		freestructs_exit(t_cubinfo *cubinfo, int err);
void		freestructs_msg(t_cubinfo *cubinfo, char *str);
void		map_floodfill(t_cubinfo *cubinfo, int x, int y);
void		draw_map(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_coord		intersection(t_coord vec, t_coord pos, t_plane plane, float *t);
void		coord_print(t_coord	coord);
t_coord		get_vector(t_vars *vars, int i, int j);
t_trgb		pick_pixel_color(t_vars *vars, t_coord vect);
void		color_print(t_trgb trgb);
void 		ftoa(float n, char* res, int afterpoint);
t_plane		*plane_factory(t_cubinfo *cubinfo);
void   		 plane_print(t_plane *planes);
void		vars_init(t_cubinfo *cubinfo, t_vars *vars);
int			is_lastplane(t_plane plane);
t_coord		rotate_vect(t_coord vect, float angle);
t_coord		 move_pc(t_vars *vars, float x);
void		vect_precalc(t_vars *vars);
void		xpm_load(t_vars *vars);
void		xpm_getaddr(t_vars *vars);
t_trgb		get_trgb_from_xpm_n(t_data *xpm, t_coord inter);
t_trgb		get_trgb_from_xpm_s(t_data *xpm, t_coord inter);
t_trgb		get_trgb_from_xpm_e(t_data *xpm, t_coord inter);
t_trgb		get_trgb_from_xpm_w(t_data *xpm, t_coord inter);
t_trgb	get_trgb_from_xpm_sprite(t_data *xpm, t_coord inter);
t_plane	create_sprite_plane(t_vars *vars, int i);
int	is_lastsprite(t_sprite sprite);
t_plane	*plane_factory_x(t_vars *vars);
t_plane	*plane_factory_y(t_vars *vars);
int keydown(int keycode, t_vars *vars);
int keyup(int keycode, t_vars *vars);
void	update_pc(t_vars *vars);
#endif