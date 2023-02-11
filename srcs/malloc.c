/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:10:24 by cbelva            #+#    #+#             */
/*   Updated: 2023/02/11 09:40:59 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_impl(size_t size)
{
	t_heap	*heap;
	t_block	*block;
	void	*result;

	if (size <= 0)
		return (NULL);
	size = (size + 15) & ~15;
	find_block(size, &heap, &block);
	if (heap && block)
	{
		cut_block(block, size, heap);
		return (SHIFT_BLOCK_META(block));
	}
	heap = get_heap(size);
	if (!heap)
		return (NULL);
	result = append_new_block(heap, size);
	return (result);
}

void	*malloc(size_t size)
{
	void	*result;

	pthread_mutex_lock(&g_ft_malloc_mutex);
	result = malloc_impl(size);
	pthread_mutex_unlock(&g_ft_malloc_mutex);
	return (result);
}
