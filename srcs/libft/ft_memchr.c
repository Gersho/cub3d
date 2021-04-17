/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:31 by kzennoun          #+#    #+#             */
/*   Updated: 2021/04/17 15:31:28 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*casted_s;
	unsigned char	casted_c;

	casted_s = (unsigned char *)s;
	casted_c = (unsigned char)c;
	while (n > 0)
	{
		if (*casted_s == casted_c)
			return (casted_s);
		casted_s++;
		n--;
	}
	return (NULL);
}
