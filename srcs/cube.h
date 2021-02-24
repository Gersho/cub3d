/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/24 13:01:34 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
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
/*
typedef struct s_mapinfo
{
	char		**map;
	int			sprite[2];
	int			spawn[2];
	int			size[2];
	char		facing;
	t_cubinfo	*cubinfo;
}				t_mapinfo;
*/

char		*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size);
char		*ft_gnl_join(char *stock, char *s2, int size);
void		ft_parse_map(char *path, t_cubinfo *cubinfo);
void		cubinfo_free(t_cubinfo *cubinfo);
void		cubinfo_print(t_cubinfo *cubinfo);
void		cubinfo_init(t_cubinfo *cubinfo);
//void		freecub_exit(t_cubinfo *cubinfo, int err);
t_cubinfo	*cubinfo_setup(t_cubinfo *cubinfo, char *path);
void		*mapinfo_setup(t_cubinfo *cubinfo, char *path);
void		error_exit(int err);
void		mapinfo_instantiate(t_cubinfo *cubinfo);
//void		mapinfo_free(t_mapinfo *mapinfo);
void		mapinfo_fill(t_cubinfo *cubinfo, char *path);
//void		mapinfo_print(t_mapinfo *mapinfo);
void		mapinfo_parse(t_cubinfo *cubinfo);
//void		mapinfo_init(t_mapinfo *mapinfo);
//void		freemap_cub_exit(t_mapinfo *mapinfo, t_cubinfo *cubinfo, int err);
void		freestructs_exit(t_cubinfo *cubinfo, int err);
void		freestructs_msg(t_cubinfo *cubinfo, char *str);
void		map_floodfill(t_cubinfo *cubinfo, int x, int y);

#endif