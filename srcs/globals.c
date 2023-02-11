/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:32:09 by artemforkun       #+#    #+#             */
/*   Updated: 2023/02/11 09:40:12 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_mutex_t	g_ft_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
t_heap			*g_heap_list = NULL;
