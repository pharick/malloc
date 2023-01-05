/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:31:35 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:10:02 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_iter;
	size_t			i;

	s_iter = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s_iter == (unsigned char)c)
		{
			return ((void *)s_iter);
		}
		s_iter++;
		i++;
	}
	return (NULL);
}
