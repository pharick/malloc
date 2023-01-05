/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:45:08 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:05:23 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s_iter;

	s_iter = (char *)s;
	len = 0;
	while (*s_iter)
	{
		len++;
		s_iter++;
	}
	while (len > 0)
	{
		if (*s_iter == (char)c)
			return (s_iter);
		s_iter--;
		len--;
	}
	if (*s_iter == (char)c)
		return (s_iter);
	return (NULL);
}
