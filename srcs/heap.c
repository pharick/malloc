/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:52:54 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/05 16:58:14 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_heap_type		get_heap_type(size_t block_size)
{
	if (block_size <= (size_t)TINY_BLOCK_SIZE)
		return (TINY);
	if (block_size <= (size_t)SMALL_BLOCK_SIZE)
		return (SMALL);
	return (LARGE);
}

static size_t	get_heap_size(size_t block_size)
{
	t_heap_type	heap_type;

	heap_type = get_heap_type(block_size);
	if (heap_type == TINY)
		return ((size_t)TINY_HEAP_SIZE);
	if (heap_type == SMALL)
		return ((size_t)SMALL_HEAP_SIZE);
	return (block_size + sizeof(t_heap) + sizeof(t_block));
}

static t_heap	*find_allocated_heap(const t_heap *heap_list, const t_heap_type type, const size_t size)
{
	t_heap	*heap;

	heap = (t_heap *)heap_list;
	while (heap)
	{
		if (heap->type == type && heap->free_size >= size)
			return (heap);
		heap = heap->next;
	}
	return (NULL);

}

static t_heap	*allocate_heap(t_heap_type type, size_t block_size)
{
	struct rlimit	rlp;
	size_t		heap_size;
	t_heap		*heap;

	heap_size = get_heap_size(block_size);
	getrlimit(RLIMIT_DATA, &rlp);
	if (heap_size > rlp.rlim_max)
		return (NULL);
	heap = (t_heap *)mmap(NULL, heap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (heap == MAP_FAILED)
		return (NULL);
	ft_bzero(heap, sizeof(heap));
	heap->type = type;
	heap->total_size = heap_size;
	heap->free_size = heap_size - sizeof(t_heap);
	return (heap);
}

t_heap		*get_heap(const size_t block_size)
{
	t_heap_type	heap_type;
	t_heap		*heap;

	heap_type = get_heap_type(block_size);
	heap = find_allocated_heap(g_heap_list, heap_type, block_size + sizeof(t_block));
	if (!heap)
	{
		heap = allocate_heap(heap_type, block_size);
		if (!heap)
			return (NULL);
		heap->next = g_heap_list;
		if (heap-> next)
			heap->next->prev = heap;
		g_heap_list = heap;

	}
	return (heap);
}
