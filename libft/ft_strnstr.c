/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:09:31 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:05:42 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*needle_iter;
	char	*haystack_iter;
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (*haystack && (i + needle_len <= len))
	{
		needle_iter = (char *)needle;
		haystack_iter = (char *)haystack;
		while (*needle_iter && (*needle_iter == *haystack_iter))
		{
			needle_iter++;
			haystack_iter++;
		}
		if (*needle_iter == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
