#include "malloc.h"

void	*realloc_impl(void *ptr, size_t size)
{
	t_heap	*heap;
	t_block	*block;
	void	*new_ptr;

	if (!ptr)
		return (malloc_impl(size));
	if (size == 0)
	{
		free_impl(ptr);
		return (NULL);
	}
	heap = NULL;
	block = NULL;
	search_block(g_heap_list, ptr, &heap, &block);
	if (!heap || !block)
		return (NULL);
	if (size == block->data_size)
		return (ptr);
	new_ptr = malloc_impl(size);
	ft_memmove(new_ptr, ptr, block->data_size > size ? size : block->data_size);
	free_impl(ptr);
	return (new_ptr);
}

void	*realloc(void *ptr, size_t size)
{
	void	*res;

	pthread_mutex_lock(&g_ft_malloc_mutex);
	res = realloc_impl(ptr, size);
	pthread_mutex_unlock(&g_ft_malloc_mutex);
	return (res);
}
