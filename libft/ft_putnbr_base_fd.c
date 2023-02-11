/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemforkunov <artemforkunov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:46:25 by cbelva            #+#    #+#             */
/*   Updated: 2023/01/27 18:38:26 by artemforkun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_base_fd(size_t n, unsigned int base, int fd)
{
	char	*abc;
	char	d;

	abc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
