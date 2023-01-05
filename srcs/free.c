/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:47 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/05 17:26:45 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		search_block(t_heap *heap_list, void *ptr, t_heap **heap_result, t_block **block_result)
{
	t_block	*block;

	block = NULL;
	while (heap)
	{
		block = (t_block *
	}
}

static void	free_impl(void *ptr)
{
	t_heap	*heap;
	t_block	*block;
	t_block	*merged_block;

	heap = g_heap_list;
	if (!ptr || !heap)
		return ;

}

void		free(void *ptr)
{
	pthread_mutex_lock(&g_ft_malloc_mutex);
	free_impl(ptr);
	pthread_mutex_unlock(&g_ft_malloc_mutex);
}

