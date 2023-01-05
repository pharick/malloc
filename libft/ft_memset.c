/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:00:20 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:09:02 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*iter;

	i = 0;
	iter = (unsigned char *)b;
	while (i < len)
	{
		*iter = (unsigned char)c;
		iter++;
		i++;
	}
	return (b);
}
