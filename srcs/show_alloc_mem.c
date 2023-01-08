/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemforkunov <artemforkunov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:32:35 by artemforkun       #+#    #+#             */
/*   Updated: 2023/01/07 19:32:59 by artemforkun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_heap	*get_last_heap(t_heap *heap)
{
	if (!heap)
		return (NULL);
	while (heap->next)
		heap = heap->next;
	return (heap);
}

static size_t	print_blocks(t_block *block)
{
	char	*start;
	char	*end;
	size_t	total;

	total = 0;
	while (block)
	{
		start = (char *)SHIFT_BLOCK_META(block);
		end = start + block->data_size;
		if (!block->freed)
		{
			ft_putnbr_base_fd((size_t)start, 16, STDOUT_FILENO);
			ft_putstr(" - ");
			ft_putnbr_base_fd((size_t)end, 16, STDOUT_FILENO);
			ft_putstr(" : ");
			ft_putnbr_base_fd(block->data_size, 10, STDOUT_FILENO);
			ft_putstr(" octets\n");
			total += block->data_size;
		}
		block = block->next;
	}
	return (total);
}

static void	show_alloc_mem_impl(void)
{
	t_heap	*first_heap;
	t_heap	*last_heap;
	size_t	total_size;

	total_size = 0;
	first_heap = g_heap_list;
	last_heap = get_last_heap(first_heap);
	while (last_heap)
	{
		if (last_heap->type == TINY)
			ft_putstr("TINY");
		else if (last_heap->type == SMALL)
			ft_putstr("SMALL");
		else
			ft_putstr("LARGE");
		ft_putstr(" : 0x");
		ft_putnbr_base_fd((size_t)(t_block *)SHIFT_HEAP_META(last_heap),
			16, STDOUT_FILENO);
		ft_putstr("\n");
		total_size += print_blocks((t_block *)SHIFT_HEAP_META(last_heap));
		last_heap = last_heap->prev;
	}
	ft_putstr("Total : ");
	ft_putnbr_base_fd(total_size, 10, STDOUT_FILENO);
	ft_putstr(" octets\n");
}

void	show_alloc_mem(void)
{
	pthread_mutex_lock(&g_ft_malloc_mutex);
	show_alloc_mem_impl();
	pthread_mutex_unlock(&g_ft_malloc_mutex);
}
