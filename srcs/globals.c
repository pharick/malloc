/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemforkunov <artemforkunov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:32:09 by artemforkun       #+#    #+#             */
/*   Updated: 2023/01/07 19:32:11 by artemforkun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_mutex_t	g_ft_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
t_heap			*g_heap_list = NULL;
