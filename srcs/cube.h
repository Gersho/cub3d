/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:39:39 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/07 14:21:56 by kzennoun         ###   ########lyon.fr   */
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
}				t_cubinfo;

int		get_next_line(int fd, char **line);
int		ft_str_find_c(char *str, char c);
char	*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size);
char	*ft_gnl_join(char *stock, char *s2, int size);
void	*ft_calloc_zero(size_t count, size_t size);
int		ft_parse_map(char *path, t_cubinfo *cubinfo);
void	cubinfo_free(t_cubinfo *cubinfo);
void 	cubinfo_print(t_cubinfo *cubinfo);
void	cubinfo_init(t_cubinfo *cubinfo);
#endif