/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:05:06 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/24 18:21:36 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;
	char	*ptr;

	if (!*little)
		return ((char *)big);
	lit_len = ft_strlen(little);
	i = -1;
	while (big[++i] && i < len)
	{
		if (ft_strncmp(&big[i], little, lit_len) == 0 && \
				i + lit_len < len)
		{
			ptr = (char *)&big[i];
			return (ptr);
		}
	}
	return (NULL);
}
