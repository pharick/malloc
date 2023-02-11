/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemforkunov <artemforkunov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:48 by artemforkun       #+#    #+#             */
/*   Updated: 2023/02/11 10:51:07 by artemforkun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/resource.h>
# include "libft.h"

# define SHIFT_HEAP_META(start) ((void *)start + sizeof(t_heap))
# define SHIFT_BLOCK_META(start) ((void *)start + sizeof(t_block))

# define TINY_HEAP_SIZE (4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_HEAP_SIZE / 128)
# define SMALL_HEAP_SIZE (16 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_HEAP_SIZE / 128)

typedef enum e_heap_type
{
	TINY,
	SMALL,
	LARGE
}						t_heap_type;

typedef struct s_heap
{
	struct s_heap	*prev;
	struct s_heap	*next;
	t_heap_type		type;
	size_t			total_size;
	size_t			free_size;
	size_t			block_count;
}						t_heap;

typedef struct s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t			data_size;
	bool			freed;
}						t_block;

extern pthread_mutex_t	g_ft_malloc_mutex;
extern t_heap			*g_heap_list;

t_heap_type				get_heap_type(size_t block_size);
t_heap					*get_heap(size_t block_size);
void					find_block(size_t size, t_heap **heap_result,
							t_block **block_result);
void					cut_block(t_block *block, size_t size, t_heap *heap);
void					*append_new_block(t_heap *heap, size_t size);
void					search_block(t_heap *heap_list, void *ptr,
							t_heap **heap_result, t_block **block_result);
t_block					*merge_block(t_heap *heap, t_block *block);
void					delete_heap(t_heap *heap);
void					*malloc_impl(size_t size);
void					free_impl(void *ptr);

void					*malloc(size_t size);
void					free(void *ptr);
void					show_alloc_mem(void);
void					show_alloc_mem_ex(void);
void					*realloc(void *ptr, size_t size);

#endif // MALLOC_H
