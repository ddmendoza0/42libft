/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:38:53 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/25 12:19:16 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	if (!lst)
		return (0);
	curr = lst;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
