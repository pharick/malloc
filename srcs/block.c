/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:59:52 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/05 17:03:38 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		init_block(t_block *block, size_t size)
{
	block->prev = NULL;
	block->next = NULL;
	block->data_size = size;
	block-> freed = false;
}

static t_block	*get_last_block(t_block *block)
{
	while (block->next)
		block = block->next;
	return (block);
}

void			find_block(size_t size, t_heap **heap_result, t_block **block_result)
{
	t_heap		*heap;
	t_block		*block;
	t_heap_type	type;

	*heap_result = NULL;
	*block_result = NULL;
	heap = g_heap_list;
	type = get_heap_type(size);
	while (heap)
	{
		block = (t_block *)SHIFT_HEAP_META(heap);
		while (block && heap->type == type)
		{
			if (block->freed && (block->data_size >= size + sizeof(t_block)))
			{
				*heap_result = heap;
				*block_result = block;
				return ;
			}
			block = block->next;
		}
		heap = heap->next;
	}
}

void			cut_block(t_block *block, size_t size, t_heap *heap)
{
	t_block	*block_remainder;

	block_remainder = SHIFT_BLOCK_META(block) + size;
	init_block(block_remainder, block->next - block_remainder);
	block_remainder->freed = true;
	block_remainder->prev = block;
	block_remainder->next = block->next;
	block->next = block_remainder;
	block->data_size = size;
	block->freed = false;
	heap->block_count++;
}

void			*append_new_block(t_heap *heap, size_t size)
{
	t_block	*new_block;
	t_block	*last_block;

	new_block = (t_block *)SHIFT_HEAP_META(heap);
	last_block = NULL;
	if (heap->block_count > 0)
	{
		last_block = get_last_block(new_block);
		new_block = (t_block *)(SHIFT_BLOCK_META(last_block) + last_block->data_size);
	}
	init_block(new_block, size);
	if (heap->block_count > 0)
	{
		last_block->next = new_block;
		new_block->prev = last_block;
	}
	heap->block_count++;
	heap->free_size -= (new_block->data_size + sizeof(t_block));
	return ((void *)SHIFT_BLOCK_META(new_block));
}

void			search_block(t_heap *heap_list, void *ptr, t_heap **heap_result, t_block **block_result)
{
	t_heap	*heap;
	t_block	*block;

	*heap_result = NULL;
	*block_result = NULL;
	heap = heap_list;
	while (heap)
	{
		block = (t_block *)SHIFT_HEAP_META(heap);
		while (block)
		{
			if (SHIFT_BLOCK_META(block) == ptr)
			{
				*heap_result = heap;
				*block_result = block;
				return ;
			}
			block = block->next;
		}
		heap = heap->next;
	}
}

t_block			*merge_block(t_heap *heap, t_block *block)
{
	if (!heap || !block)
		return (NULL);
	if (block->next && block->next->freed)
	{
		block->data_size += block->next->data_size + sizeof(t_block);
		if (block->next->next)
			block->next->next->prev = block;
		block->next = block->next->next;
		heap->block_count--;
	}
	if (block->prev && block->prev->freed)
	{
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block->prev->data_size += block->data_size + sizeof(t_block);
		heap->block_count--;
		return (block->prev);
	}
	return block;
}
