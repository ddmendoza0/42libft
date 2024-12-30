/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:23:25 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/30 15:46:44 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nsize(long n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			n_long;
	char			*str_n;
	unsigned int	is_neg;
	unsigned int	len;

	n_long = (long)n;
	is_neg = 0;
	if (n_long < 0)
	{
		is_neg = 1;
		n_long *= -1;
	}
	len = ft_nsize(n_long);
	str_n = (char *)malloc((len + is_neg + 1) * sizeof(char));
	if (!str_n)
		return (NULL);
	str_n[len + is_neg] = '\0';
	while (len > 0)
	{
		str_n[--len + is_neg] = (n_long % 10) + '0';
		n_long /= 10;
	}
	if (is_neg)
		str_n[0] = '-';
	return (str_n);
}
