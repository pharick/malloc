/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ntokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:10:34 by cbelva            #+#    #+#             */
/*   Updated: 2021/03/05 10:21:54 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_ntokens(char **array, int n)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < n)
		free(array[i++]);
	free(array);
}
