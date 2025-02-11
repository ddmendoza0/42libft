/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:59:53 by dmendoza          #+#    #+#             */
/*   Updated: 2025/02/11 11:29:43 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printf_char(char c)
{
	ft_putchar(c);
	return (1);
}

static int	ft_handle_format(char const **format, va_list args)
{
	int	p;

	p = 0;
	if (**format == 'd' || **format == 'i')
		p += printf_nb(va_arg(args, int));
	else if (**format == 's')
		p += printf_str(va_arg(args, char *));
	else if (**format == 'p')
		p += printf_p(va_arg(args, void *));
	else if (**format == 'u')
		p += printf_nbu(va_arg(args, unsigned int));
	else if (**format == 'c')
		p += printf_char((unsigned char)va_arg(args, int));
	else if (**format == '%')
		p += printf_char('%');
	else if (**format == 'x')
		p += printf_hex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		p += printf_hex(va_arg(args, unsigned int), 1);
	return (p);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			p;

	if (!format)
		return (-1);
	if (write(1, "", 0) == -1)
		return (-1);
	p = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			p += ft_handle_format(&format, args);
		}
		else
			p += printf_char(*format);
		format++;
	}
	va_end(args);
	return (p);
}
