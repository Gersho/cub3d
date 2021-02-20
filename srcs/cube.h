/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/20 16:05:21 by kzennoun         ###   ########lyon.fr   */
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
	int		res[2];
	char	*path_N;
	char	*path_S;
	char	*path_E;
	char	*path_W;
	char	*path_sprite;
	int		color_floor[3];
	int		color_ceil[3];
	int		map_size[2];
	int		map_start;
}				t_cubinfo;

typedef struct s_mapinfo
{
	char	**map;
	int		sprite[2];
	int		spawn[2];
	int		size[2];
	char	facing;
}				t_mapinfo;

char		*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size);
char		*ft_gnl_join(char *stock, char *s2, int size);
void		ft_parse_map(char *path, t_cubinfo *cubinfo);
void		cubinfo_free(t_cubinfo *cubinfo);
void		cubinfo_print(t_cubinfo *cubinfo);
void		cubinfo_init(t_cubinfo *cubinfo);
//void		freecub_exit(t_cubinfo *cubinfo, int err);
t_cubinfo	*cubinfo_setup(t_cubinfo *cubinfo, char *path);
t_mapinfo	*mapinfo_setup(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path);
void		error_exit(int err);
void		mapinfo_instantiate(t_mapinfo *mapinfo, t_cubinfo *cubinfo);
void		mapinfo_free(t_mapinfo *mapinfo);
void		mapinfo_fill(t_mapinfo *mapinfo, t_cubinfo *cubinfo, char *path);
void		mapinfo_print(t_mapinfo *mapinfo);
void		mapinfo_parse(t_mapinfo *mapinfo);
//void		freemap_cub_exit(t_mapinfo *mapinfo, t_cubinfo *cubinfo, int err);
void		freestructs_exit(t_mapinfo *mapinfo, t_cubinfo *cubinfo, int err);
#endif