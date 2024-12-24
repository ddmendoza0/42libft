/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:31:55 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/24 12:14:42 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstrs(const char *s, char c)
{
	size_t			cnt;

	if (!*s)
		return (0);
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			cnt++;
		while (*s != c && *s)
			s++;
	}
	return (cnt);
}

static void	*ft_memfree(char **s_split, unsigned int i)
{
	while (i > 0)
		free(s_split[--i]);
	free(s_split);
	return (NULL);
}

static char	**ft_findstr(char const *s, char c, char **s_split)
{
	size_t	str_len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				str_len = ft_strlen(s);
			else
				str_len = ft_strchr(s, c) - s;
			s_split[i] = ft_substr(s, 0, str_len);
			if (!s_split[i++])
			{
				ft_memfree(s_split, i - 1);
				return (NULL);
			}
			s += str_len;
		}
	}
	s_split[i] = NULL;
	return (s_split);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;

	s_split = (char **)malloc((ft_countstrs(s, c) + 1) * sizeof(char *));
	if (!s_split || !s)
		return (NULL);
	ft_findstr(s, c, s_split);
	if (!s_split)
		return (NULL);
	return (s_split);
}
