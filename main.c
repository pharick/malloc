/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemforkunov <artemforkunov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:46:21 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/07 19:33:45 by artemforkun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

#define STR_COUNT 10
#define STR_LEN_START 10
#define STR_LEN_STEP 20

int	main(void)
{
	char	**strs;
	int		i;
	int		size;

	show_alloc_mem();
	strs = (char **)malloc(sizeof(char **) * STR_COUNT);
	show_alloc_mem();
	i = 0;
	size = STR_LEN_START;
	while (i < STR_COUNT)
	{
		strs[i] = (char *)malloc(sizeof(char) * size);
		show_alloc_mem();
		size += STR_LEN_STEP;
		i++;
	}
	i = 0;
	while (i < STR_COUNT)
	{
		free(strs[i]);
		show_alloc_mem();
		i++;
	}
	free(strs);
	show_alloc_mem();
	return (0);
}
