/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:52:23 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/20 10:10:43 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rc;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			rc = (char *)&s[i];
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else if (c == *rc)
		return (rc);
	return (NULL);
}
