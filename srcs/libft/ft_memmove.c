/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:39 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/25 02:13:58 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*casted_dst;
	unsigned char	*casted_src;

	casted_dst = (unsigned char *)dst;
	casted_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			casted_dst[len] = casted_src[len];
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
