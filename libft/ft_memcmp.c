/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:26:45 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:09:30 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_iter;
	unsigned char	*s2_iter;

	i = 0;
	s1_iter = (unsigned char *)s1;
	s2_iter = (unsigned char *)s2;
	while (i < n)
	{
		if (*s1_iter != *s2_iter)
			return (*s1_iter - *s2_iter);
		s1_iter++;
		s2_iter++;
		i++;
	}
	return (0);
}
