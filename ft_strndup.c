/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:45:06 by dmendoza          #+#    #+#             */
/*   Updated: 2025/07/11 19:48:42 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libf.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < n && s[i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
