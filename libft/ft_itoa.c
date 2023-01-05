/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:59:33 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 19:42:43 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_digits(long long number, int is_minus)
{
	size_t	len;

	len = 1;
	number /= 10;
	while (number)
	{
		number /= 10;
		len++;
	}
	if (is_minus)
		len++;
	return (len);
}

char	*ft_itoa(long long n)
{
	size_t		len;
	int			is_minus;
	char		*result;
	char		*iter;

	is_minus = n < 0;
	if (is_minus)
		n = -n;
	len = ft_count_digits(n, is_minus);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	iter = result + len;
	*(iter--) = '\0';
	*(iter--) = n % 10 + '0';
	n /= 10;
	while (n)
	{
		*(iter--) = n % 10 + '0';
		n /= 10;
	}
	if (is_minus)
		*iter = '-';
	return (result);
}
