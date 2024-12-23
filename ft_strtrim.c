/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:30:15 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/23 16:35:11 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	start;
	size_t	end;
	size_t	i;

	i = -1;
	start = 0;
	while (s1[++i] && ft_strchr(set, s1[i]) != NULL)
		start++;
	i = ft_strlen(s1);
	end = 0;
	while (ft_strchr(set, s1[--i]) != NULL && &s1[i] != &s1[start])
		end++;
	s_trim = ft_substr(s1, start, ft_strlen(s1) - start - end);
	if (s_trim == NULL)
		return (NULL);
	return (s_trim);
}
