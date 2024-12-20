/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:32:02 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/20 13:40:02 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const unsigned char		*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	i = -1;
	while (s1_ptr[++i] && s2_ptr[i] && i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
	}
	if (i < n)
		return (s1_ptr[i] - s2_ptr[i]);
	return (0);
}

