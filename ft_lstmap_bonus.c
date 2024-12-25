/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:17:25 by dmendoza          #+#    #+#             */
/*   Updated: 2024/12/25 20:49:53 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;
	t_list	*curr;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	while (curr)
	{
		node_new = ft_lstnew(f(curr->content));
		if (!node_new)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, node_new);
		curr = curr->next;
	}
	return (lst_new);
}