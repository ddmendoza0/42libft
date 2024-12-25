/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:23:25 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/25 10:32:50 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reversestr(char *str, int len)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end --;
	}
	return (str);
}

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
	unsigned int	i;
	long			n_long;
	char			*str_n;

	n_long = n;
	if (n < 0)
		n_long *= -1;
	str_n = (char *)malloc((ft_nsize(n_long) + 1) * sizeof(char *));
	if (!str_n)
		return (NULL);
	i = 0;
	if (n_long == 0)
		str_n[i++] = '0';
	while (n_long != 0)
	{
		str_n[i++] = (n_long % 10) + '0';
		n_long /= 10;
	}
	if (n < 0)
		str_n[i++] = '-';
	str_n[i] = '\0';
	return (ft_reversestr(str_n, i));
}
