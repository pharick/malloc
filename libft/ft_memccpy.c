/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:07:17 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:10:08 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_iter;
	unsigned char	*src_iter;

	i = 0;
	dst_iter = (unsigned char *)dst;
	src_iter = (unsigned char *)src;
	while (i < n)
	{
		*dst_iter = *src_iter;
		if (*dst_iter == (unsigned char)c)
		{
			return ((void *)(dst_iter + 1));
		}
		dst_iter++;
		src_iter++;
		i++;
	}
	return (NULL);
}
