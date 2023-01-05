/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:09:11 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:09:11 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_iter;
	char	*src_iter;
	char	d;

	if (!dst && !src)
		return (dst);
	i = 0;
	dst_iter = (char *)dst;
	src_iter = (char *)src;
	d = 1;
	if (src < dst)
	{
		dst_iter = (char *)(dst + len - 1);
		src_iter = (char *)(src + len - 1);
		d = -1;
	}
	while (i < len)
	{
		*dst_iter = *src_iter;
		dst_iter += d;
		src_iter += d;
		i++;
	}
	return (dst);
}
