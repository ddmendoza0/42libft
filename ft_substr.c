/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:25:47 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/24 12:18:24 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *)malloc(1));
	subs = (char *)malloc((len + 1) * sizeof(char *));
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}
