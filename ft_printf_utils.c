/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:42 by dmendoza          #+#    #+#             */
/*   Updated: 2025/02/11 11:23:39 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

unsigned int	ft_hexlen(unsigned long nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned long nb, unsigned int upper)
{
	char	*hex_char;

	if (upper)
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, upper);
	write(1, &hex_char[nb % 16], 1);
}

int	ft_ulen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
