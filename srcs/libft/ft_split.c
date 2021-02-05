/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:02:12 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/02 17:15:44 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_sep_count(char const *s, char c)
{
	int		i;
	int		sep_count;

	sep_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			sep_count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (sep_count);
}

int		ft_get_split_size(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_free_all_2d(char **ptr, int j)
{
	if (j < 0)
		j = 0;
	while (j >= 0)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		split_size;
	char	**ptr;

	if (!s || !(ptr = malloc((ft_get_sep_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			split_size = ft_get_split_size((char *)s + i, c);
			if (!(ptr[j] = ft_substr(s, i, split_size)))
				return (ft_free_all_2d(ptr, j - 1));
			i += split_size;
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}
