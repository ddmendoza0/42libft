/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:25:06 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/20 13:53:51 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const unsigned char	*s_ptr;

	s_ptr = (const unsigned char *)s;
	i = -1;
	while (s_ptr[++i])
	{
		if (s_ptr[i] == (char)c)
			return ((char *)&s_ptr[i]);
	}
	return (NULL);
}
