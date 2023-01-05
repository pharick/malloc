/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:31:54 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 17:33:20 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		is_minus;
	long	next;

	while (ft_isspace(*str))
		str++;
	is_minus = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		next = n * 10 + (*str - '0');
		if (next < n && is_minus)
			return (0);
		else if (next < n)
			return (-1);
		n = next;
		str++;
	}
	if (is_minus)
		return ((int)-n);
	return ((int)n);
}
