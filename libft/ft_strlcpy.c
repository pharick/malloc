/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:50:54 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/01 22:46:43 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*src && (i < dstsize - 1))
	{
		*(dst++) = *(src++);
		i++;
	}
	while (*src)
	{
		i++;
		src++;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (i);
}
