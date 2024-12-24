/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:41 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/24 12:19:07 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*s_join;

	t_len = ft_strlen(s1) + ft_strlen(s2);
	s_join = (char *)malloc((t_len + 1) * sizeof(char *));
	if (s_join == NULL)
		return (NULL);
	ft_strlcpy(s_join, s1, t_len + 1);
	ft_strlcat(s_join, s2, t_len + 1);
	return (s_join);
}
