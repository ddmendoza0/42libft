/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:05:23 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/30 16:23:44 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t_size;
	void	*ptr;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	t_size = nmemb * size;
	if (t_size == 0)
		return ((void *)malloc(0));
	ptr = (void *)malloc(t_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, t_size);
	return (ptr);
}
