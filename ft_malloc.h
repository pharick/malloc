/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:09:15 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/05 17:10:03 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
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
}				t_heap_type;

typedef struct s_heap
{
	struct s_heap	*prev;
	struct s_heap	*next;
	t_heap_type		type;
	size_t			total_size;
	size_t			free_size;
	size_t			block_count;
}				t_heap;

typedef struct s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t			data_size;
	bool			freed;
}				t_block;

pthread_mutex_t	g_ft_malloc_mutex;
t_heap			*g_heap_list;

t_heap_type		get_heap_type(size_t block_size);
t_heap			*get_heap(const size_t block_size);
void			find_block(size_t size, t_heap **heap_result, t_block **block_result);
void			cut_block(t_block *block, size_t size, t_heap *heap);
void			*append_new_block(t_heap *heap, size_t size);
void			*malloc(size_t size);
void			free(void *ptr);

#endif //FT_MALLOC_H
