/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:45 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/19 15:31:49 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_zero(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*str;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < (count * size))
	{
		str[i] = (unsigned char)0;
		i++;
	}
	return (ptr);
}

int		ft_str_find_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		free_and_return_int(char *ptr, int ret)
{
	free(ptr);
	ptr = NULL;
	return (ret);
}

int		gnl_bis(char **line, int nl_i, int read_ret, char **s)
{
	char	*temp;

	if (read_ret == 0 && ((nl_i = ft_str_find_c(*s, '\n')) == -1))
	{
		if ((*line = ft_gnl_substr(*s, ft_strlen(*s), 0, ft_strlen(*s)))
		== NULL)
			return (free_and_return_int(*s, -1));
		free(*s);
		*s = NULL;
		return (0);
	}
	if (((temp = ft_gnl_substr(*s, ft_strlen(*s), nl_i + 1, ft_strlen(*s) -
	nl_i - 1)) == NULL) || (((*line = ft_gnl_substr(*s, ft_strlen(*s), 0, nl_i))
	== NULL)))
		return (free_and_return_int(*s, -1));
	free(*s);
	*s = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static char		*s;
	int				read_ret;
	int				nl_i;
	char			*temp;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0 || !line)
	{
		if (s)
			return (free_and_return_int(s, -1));
		return (-1);
	}
	if (!s)
		if (!(s = ft_calloc_zero(1, sizeof(char))))
			return (-1);
	read_ret = 1;
	while ((nl_i = ft_str_find_c(s, '\n')) == -1 && (read_ret > 0))
	{
		if (((read_ret = read(fd, buffer, BUFFER_SIZE)) == -1)
			|| ((temp = ft_gnl_join(s, buffer, read_ret)) == NULL))
			return (free_and_return_int(s, -1));
		free(s);
		s = temp;
	}
	return (gnl_bis(line, nl_i, read_ret, &s));
}
