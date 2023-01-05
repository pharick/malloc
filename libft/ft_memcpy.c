/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:05:25 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:09:25 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_iter;
	char	*src_iter;

	if (!dst && !src)
		return (dst);
	i = 0;
	dst_iter = (char *)dst;
	src_iter = (char *)src;
	while (i < n)
	{
		*dst_iter = *src_iter;
		dst_iter++;
		src_iter++;
		i++;
	}
	return (dst);
}
