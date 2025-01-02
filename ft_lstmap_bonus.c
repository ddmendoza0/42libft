/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:17:25 by dmendoza          #+#    #+#             */
/*   Updated: 2025/01/02 16:03:01 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;

	if (!lst || !f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		node_new = ft_lstnew(f(lst->content));
		if (!node_new)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, node_new);
		lst = lst->next;
	}
	return (lst_new);
}
