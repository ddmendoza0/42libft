/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:05:06 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/20 11:40:45 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (little[0] == '\0')
		return ((char *)big);
	i = -1;
	while (big[++i] && i < len)
	{
		if (ft_strncmp(&big[i], &little[0], ft_strlen(little)) == 0)
		{
			ptr = (char *)&big[i];
			return (ptr);
		}
	}
	return (NULL);
}
