/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:55:29 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/06 11:59:58 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*result;
	t_list	*iter;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	if (result == NULL)
		return (NULL);
	iter = result;
	node = lst->next;
	while (node)
	{
		new = ft_lstnew((*f)(node->content));
		if (new == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		iter->next = new;
		iter = new;
		node = node->next;
	}
	return (result);
}
