/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:01:18 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/30 15:05:43 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	dst_size;
	char	*dst;
	size_t	i;

	dst_size = ft_strlen(s);
	dst = (char *)malloc((dst_size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}
