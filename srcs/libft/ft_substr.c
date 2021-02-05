/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 06:46:44 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/02 16:01:34 by kzennoun         ###   ########lyon.fr   */
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
		if (!(ptr = malloc((len_s - start + 1) * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(ptr = malloc((len + 1) * sizeof(char))))
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, len + 1);
	ptr[len] = '\0';
	return (ptr);
}
