/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:23:28 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/19 18:36:21 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			srclen;
	size_t			dstlen;
	unsigned int	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = -1;
	while (src[++i] && i < (size - dstlen - 1))
		dst[i + dstlen] = src[i];
	dst[i + dstlen] = '\0';
	return (srclen + dstlen);
}
