/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:00:16 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/19 17:18:14 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	unsigned int	i;

	srclen = ft_strlen(src);
	i = -1;
	while (src[++i] && i < size)
		dst[i] = src[i];
	dst[i] = '\0';
	return (srclen);
}
