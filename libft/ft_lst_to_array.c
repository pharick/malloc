/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:29:45 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:10:30 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst)
{
	t_list	*node;
	void	**array;
	void	**iter;

	if (lst == NULL)
		return (NULL);
	array = (void **)malloc((ft_lstsize(lst) + 1) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	iter = array;
	node = lst;
	while (node)
	{
		*iter = node->content;
		node = node->next;
		iter++;
	}
	*iter = NULL;
	return (array);
}
