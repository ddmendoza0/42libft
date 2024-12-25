/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:50:29 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/25 10:35:31 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = (long)n;
	if (n < 0)
	{
		write(fd, &"-", 1);
		n_long *= -1;
	}
	if (n_long >= 10)
		ft_putnbr_fd(n_long / 10, fd);
	write(fd, &"0123456789"[n_long % 10], 1);
}
