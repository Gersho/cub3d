/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:46:44 by kzennoun          #+#    #+#             */
/*   Updated: 2021/02/11 14:02:33 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len_s - start < len)
	{
		ptr = malloc((len_s - start + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
	}
	else
	{
		ptr = malloc((len + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, len + 1);
	ptr[len] = '\0';
	return (ptr);
}
