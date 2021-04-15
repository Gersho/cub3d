/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:29:49 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/15 12:30:35 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	abort_parse_cf(char *line, t_cubinfo *cubinfo, char **ptr, char *m)
{
	ptr_minifree(ptr);
	free(line);
	freestructs_msg(cubinfo, m);
}

static void	fill_cf(char *line, t_cubinfo *cubinfo, int len, char **ptr)
{
	if (line[0] == 'C')
	{
		if (cubinfo->color_ceil[len - 1] != -1)
			abort_parse_cf(line, cubinfo, ptr, "color set twice");
		cubinfo->color_ceil[len - 1] = ft_atoi(ptr[len - 1]);
		if (cubinfo->color_ceil[len - 1] == 0
			&& ft_str_index_c(ptr[len - 1], '0') == -1)
			abort_parse_cf(line, cubinfo, ptr, "color is invalid");
	}
	else
	{
		if (cubinfo->color_floor[len - 1] != -1)
			abort_parse_cf(line, cubinfo, ptr, "color set twice");
		cubinfo->color_floor[len - 1] = ft_atoi(ptr[len - 1]);
		if (cubinfo->color_floor[len - 1] == 0
			&& ft_str_index_c(ptr[len - 1], '0') == -1)
			abort_parse_cf(line, cubinfo, ptr, "color is invalid");
	}
}

static void	precheck_cf(char *line, t_cubinfo *cubinfo, int *len, char ***ptr)
{
	int	i;

	*len = 0;
	i = -1;
	while (line[++i])
		if (line[i] == ',')
			(*len)++;
	if (*len != 2)
	{
		free(line);
		freestructs_msg(cubinfo, "color(s) not formated properly.");
	}
	*ptr = ft_split(line + 1, ',');
	if (*ptr == NULL)
	{
		free(line);
		freestructs_exit(cubinfo, -1);
	}
	*len = 0;
	while ((*ptr)[*len] != NULL)
		(*len)++;
}

void	ft_parse_cf(char *line, t_cubinfo *cubinfo)
{
	char	**ptr;
	int		len;
	int		i;

	precheck_cf(line, cubinfo, &len, &ptr);
	if (len != 3)
	{
		ft_free_all_2d(ptr, len - 1);
		free(line);
		freestructs_msg(cubinfo, "color(s) not formated properly.");
	}
	while (len > 0)
	{
		fill_cf(line, cubinfo, len, ptr);
		i = 0;
		while (i < (int)ft_strlen(ptr[len - 1]))
		{
			if (!(ft_isdigit(ptr[len - 1][i]) || ptr[len - 1][i] == ' '))
				abort_parse_cf(line, cubinfo, ptr, "color is invalid");
			i++;
		}
		len--;
	}
	ptr_minifree(ptr);
}
