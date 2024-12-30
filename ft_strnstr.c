/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:05:06 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/30 12:03:10 by dmendoza         ###   ########.fr       */
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
	if (lit_len == 0)
		return ((char *)big);
	i = -1;
	while (big[++i] && i + lit_len <= len)
	{
		if (ft_strncmp(&big[i], little, lit_len) == 0)
		{
			ptr = (char *)&big[i];
			return (ptr);
		}
	}
	return (NULL);
}
