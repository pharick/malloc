#include "malloc.h"

pthread_mutex_t	g_ft_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
t_heap			*g_heap_list = NULL;
