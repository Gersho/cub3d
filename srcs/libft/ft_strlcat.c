/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:49 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/02 17:12:41 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int		dest_len;
	unsigned int		src_len;
	unsigned int		i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && (dest_len + i) < dstsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dstsize != 0 || dest_len < dstsize)
		dest[dest_len + i] = '\0';
	if (dstsize == 0 || dest_len > dstsize)
		return (dstsize + src_len);
	return (dest_len + src_len);
}
