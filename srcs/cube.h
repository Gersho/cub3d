/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/03/04 14:33:07 by kzennoun         ###   ########lyon.fr   */
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

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;   
}               t_vars;

typedef	struct	s_pc
{
	int			pos[3];
}				t_pc;


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
void		draw_map(t_cubinfo *cubinfo);
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
#endif