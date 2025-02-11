/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:03:40 by dmendoza          #+#    #+#             */
/*   Updated: 2025/02/11 11:08:15 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_str(char *str)
{
	int	printed;
	int	i;

	printed = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		printed = 6;
		return (printed);
	}
	i = -1;
	while (str[++i])
	{
		printed++;
		ft_putchar(str[i]);
	}
	return (printed);
}

int	printf_p(void *ptr)
{
	unsigned long	address;
	int				printed;

	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	printed = 0;
	printed += write(1, "0x", 2);
	ft_puthex(address, 0);
	printed += ft_hexlen(address);
	return (printed);
}

int	printf_nbu(unsigned int nb)
{
	int		len;
	char	*str;
	int		i;
	int		printed;

	len = ft_ulen(nb);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (-1);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	printed = 0;
	i = -1;
	while (str[++i])
		printed += write(1, &str[i], 1);
	free(str);
	return (printed);
}

int	printf_nb(int nb)
{
	char	*num;
	int		printed;
	int		i;

	printed = 0;
	if (nb < 0)
		num = ft_itoa(nb);
	else
		num = ft_itoa(nb);
	i = -1;
	while (num[++i])
	{
		printed++;
		ft_putchar(num[i]);
	}
	free (num);
	return (printed);
}

int	printf_hex(unsigned int nb, int upper)
{
	int	printed;

	if (nb == 0)
		return (write(1, "0", 1));
	printed = 0;
	ft_puthex(nb, upper);
	printed += ft_hexlen(nb);
	return (printed);
}
