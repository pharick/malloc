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

#include "malloc.h"

static void	free_impl(void *ptr)
{
	t_heap	*heap;
	t_block	*block;

	if (!ptr || !g_heap_list)
		return ;
	search_block(g_heap_list, ptr, &heap, &block);
	if (!heap || !block)
		return ;
	block->freed = true;
	block = merge_block(heap, block);
	if (block->freed && !block->next)
	{
		if (block->prev)
			block->prev->next = NULL;
		heap->free_size += block->data_size + sizeof(t_block);
		heap->block_count--;
		if (heap->block_count <= 0)
			delete_heap(heap);
	}
}

void		free(void *ptr)
{
	ft_putstr("free\n");
	pthread_mutex_lock(&g_ft_malloc_mutex);
	free_impl(ptr);
	pthread_mutex_unlock(&g_ft_malloc_mutex);
}

