/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:23:25 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/24 13:43:46 by dmendoza         ###   ########.fr       */
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

static unsigned int	ft_nsize(int n)
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
	unsigned int	is_negative;
	unsigned int	i;
	char			*str_n;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	str_n = (char *)malloc((ft_nsize(n) + 1) * sizeof(char *));
	if (!str_n)
		return (NULL);
	i = 0;
	if (n == 0)
		str_n[i++] = '0';
	while (n != 0)
	{
		str_n[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str_n[i++] = '-';
	str_n[i] = '\0';
	return (ft_reversestr(str_n, i));
}
