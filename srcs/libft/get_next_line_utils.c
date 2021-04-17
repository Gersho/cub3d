/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:48 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/16 12:21:07 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_join(char *stock, char *s2, int size)
{
	char	*ptr;
	int		len;

	if (!stock || !s2)
		return (NULL);
	len = ft_strlen(stock);
	ptr = ft_calloc((len + size + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy((ft_memcpy(ptr, stock, len) + len), s2, size);
	return (ptr);
}

char	*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= len_s)
		size = 0;
	if (len_s - start < size)
	{
		ptr = ft_calloc((len_s - start + 1), sizeof(char));
		if (!ptr)
			return (NULL);
	}
	else
	{
		ptr = ft_calloc((size + 1), sizeof(char));
		if (!ptr)
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, size + 1);
	return (ptr);
}
