/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:29 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/25 01:25:21 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*casted_dst;
	unsigned char	*casted_src;
	unsigned char	casted_c;
	size_t			i;

	casted_dst = (unsigned char *)dst;
	casted_src = (unsigned char *)src;
	casted_c = (unsigned char)c;
	if (dst == NULL && src == NULL)
		return (casted_dst);
	i = 0;
	while (i < n)
	{
		casted_dst[i] = casted_src[i];
		if (casted_src[i] == casted_c)
			return (casted_dst + i + 1);
		i++;
	}
	return (NULL);
}
