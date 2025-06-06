/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:34:12 by dmendoza          #+#    #+#             */
/*   Updated: 2025/06/06 18:37:13 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_integer_part(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_decimal_part(const char *str, int *i)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			result += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;

	if (!str)
		return (0.0);
	i = 0;
	sign = 1;
	result = 0.0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = parse_integer_part(str, &i);
	result += parse_decimal_part(str, &i);
	return (result * sign);
}
