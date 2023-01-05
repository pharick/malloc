/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:12:47 by cbelva            #+#    #+#             */
/*   Updated: 2021/02/20 15:16:36 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*elem;

	prev = NULL;
	elem = *begin_list;
	while (elem)
	{
		if ((*cmp)(elem->content, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = elem->next;
			else
				prev->next = elem->next;
			(*free_fct)(elem->content);
			free(elem);
		}
		prev = elem;
		elem = elem->next;
	}
}
