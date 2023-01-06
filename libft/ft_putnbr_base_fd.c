/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:46:25 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/05 14:51:01 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_base_fd(size_t n, unsigned int base, int fd)
{
	char	*abc;
	char	d;

	abc = "0123456789ABCDEFGHIJKLMNOPQRSTUIVWXYZ";
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_base_fd(-n, base, fd);
	}
	else
	{
		d = abc[n % base];
		if (n / base > 0)
			ft_putnbr_base_fd(n / base, base, fd);
		write(fd, &d, 1);
	}
}
