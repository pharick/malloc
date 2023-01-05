/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:44:09 by cbelva            #+#    #+#             */
/*   Updated: 2020/10/31 22:34:26 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*m;

	len = count * size;
	m = malloc(len);
	if (!m)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(m, len);
	return (m);
}
