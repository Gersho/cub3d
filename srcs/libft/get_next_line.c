/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:45 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/19 13:09:12 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_and_return_int(char *ptr, int ret)
{
	free(ptr);
	ptr = NULL;
	return (ret);
}

int	gnl_bis(char **line, int nl_i, int read_ret, char **s)
{
	char	*temp;

	nl_i = ft_str_index_c(*s, '\n');
	if (read_ret == 0 && (nl_i == -1))
	{
		*line = ft_gnl_substr(*s, ft_strlen(*s), 0, ft_strlen(*s));
		if (*line == NULL)
			return (free_and_return_int(*s, -1));
		free(*s);
		*s = NULL;
		return (0);
	}
	temp = ft_gnl_substr(*s, ft_strlen(*s), nl_i + 1, ft_strlen(*s) - nl_i - 1);
	*line = ft_gnl_substr(*s, ft_strlen(*s), 0, nl_i);
	if (temp == NULL || *line == NULL)
		return (free_and_return_int(*s, -1));
	free(*s);
	*s = temp;
	return (1);
}

int	gnl_checks(int fd, char **line, char **s)
{
	if (fd < 0 || read(fd, 0, 0) || !line)
	{
		if (*s)
			return (free_and_return_int(*s, -1));
		return (-1);
	}
	if (!*s)
	{
		*s = ft_calloc(1, sizeof(char));
		if (!*s)
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[128];
	static char		*s;
	int				read_ret;
	int				nl_i;
	char			*temp;

	if (gnl_checks(fd, line, &s) == -1)
		return (-1);
	read_ret = 1;
	nl_i = -1;
	while (nl_i == -1 && (read_ret > 0))
	{
		read_ret = read(fd, buffer, 128);
		temp = ft_gnl_join(s, buffer, read_ret);
		if (read_ret == -1 || temp == NULL)
			return (free_and_return_int(s, -1));
		free(s);
		s = temp;
		nl_i = ft_str_index_c(s, '\n');
	}
	return (gnl_bis(line, nl_i, read_ret, &s));
}
