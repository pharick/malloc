/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:41 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:07:01 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_iter;

	s_iter = (char *)s;
	while (*s_iter)
	{
		if (*s_iter == (char)c)
			return (s_iter);
		s_iter++;
	}
	if (*s_iter == (char)c)
		return (s_iter);
	return (NULL);
}
