/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:36 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/25 01:47:32 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*casted_dst;
	unsigned char	*casted_src;
	unsigned int	i;

	casted_dst = (unsigned char *)dst;
	casted_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (casted_dst);
	i = 0;
	while (i < n)
	{
		casted_dst[i] = casted_src[i];
		i++;
	}
	return (casted_dst);
}
