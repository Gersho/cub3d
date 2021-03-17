/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/17 10:55:49 by kzennoun         ###   ########lyon.fr   */
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
# include <stdio.h>
# include <math.h>

typedef	struct	s_plane
{
	float	a;
	float	b;
	float	c;
	float	d;
}				t_plane;

typedef	struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;


typedef struct s_cubinfo
{
	char	*path_N;
	char	*path_S;
	char	*path_E;
	char	*path_W;
	char	*path_sprite;
	char	**map;
	int		sprite[2];
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

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;   
    t_trgb      trgb;
}               t_data;

typedef	struct	s_pc
{
	t_coord		pos;
	float		head_tilt;
	float		angle;
}				t_pc;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    t_data      img;
	t_cubinfo	*cubinfo;
	t_pc		pc;
	t_trgb      trgb_sky;
	t_trgb      trgb_floor;
	t_trgb      trgb_text;
	t_trgb		trgb_wall;
	t_trgb		trgb_wall_n;
	t_trgb		trgb_wall_s;
	t_trgb		trgb_wall_e;
	t_trgb		trgb_wall_w;
	t_plane		*planes;
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
t_coord		intersection(t_vect vec, t_coord pos, t_plane plane, float *t);
void		coord_print(t_coord	coord);
t_vect		get_vector(t_vars *vars, int i, int j);
t_trgb		pick_pixel_color(t_vars *vars, t_vect vect);
void	color_print(t_trgb trgb);
void ftoa(float n, char* res, int afterpoint);
t_plane	*plane_factory(t_cubinfo *cubinfo);
void    plane_print(t_plane *planes);
void	vars_init(t_cubinfo *cubinfo, t_vars *vars);
int	is_lastplane(t_plane plane);
#endif