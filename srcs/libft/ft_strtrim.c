/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:47:22 by kzennoun          #+#    #+#             */
/*   Updated: 2020/11/26 12:33:32 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, (int)s1[i]) && s1[i] != '\0')
		i++;
	if (i == len)
	{
		if (!(ptr = malloc(sizeof(char))))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (ft_strchr(set, (int)s1[len]))
		len--;
	if (!(ptr = malloc((len - i + 2) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, (s1 + i), (len - i + 1));
	ptr[len - i + 1] = '\0';
	return (ptr);
}
