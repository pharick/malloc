/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:08:35 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:01:09 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	shift_buffer(char *buffer, int n)
{
	char	*iter;

	iter = buffer + n + 1;
	while (*iter != '\0')
		*(buffer++) = *(iter++);
	*buffer = '\0';
}

static int	append_buffer(char *buffer, char *line, size_t *f_len)
{
	size_t	n;

	n = ft_strccat(line, buffer, '\n');
	if (*(buffer + n) == '\n')
	{
		shift_buffer(buffer, n);
		return (1);
	}
	*f_len += n;
	return (0);
}

static int	check_len(char **line, size_t len, size_t f_len, ssize_t ret)
{
	if (f_len + ret > len)
	{
		*line = ft_realloc(*line, len + 1, len * 2 + 1);
		len = len * 2;
	}
	return (len);
}

static int	read_from_file(int fd, char **buffer, char **line, size_t f_len)
{
	size_t	len;
	ssize_t	ret;
	size_t	n;

	ret = 0;
	len = BUFFER_SIZE;
	ret = read(fd, *buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		*(*buffer + ret) = '\0';
		len = check_len(line, len, f_len, ret);
		n = ft_strccat(*line, *buffer, '\n');
		if (*(*buffer + n) == '\n')
		{
			shift_buffer(*buffer, n);
			return (1);
		}
		f_len += n;
		ret = read(fd, *buffer, BUFFER_SIZE);
	}
	free(*buffer);
	*buffer = NULL;
	if (ret < 0)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffers[1024];
	size_t		f_len;

	if (fd < 0 || fd > 1023)
		return (-1);
	f_len = 0;
	*line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*line == NULL)
		return (-1);
	**line = '\0';
	if (buffers[fd] == NULL)
	{
		buffers[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffers[fd] == NULL)
			return (-1);
	}
	else if (*buffers[fd] != '\0')
	{
		if (append_buffer(buffers[fd], *line, &f_len) == 1)
			return (1);
	}
	return (read_from_file(fd, &buffers[fd], line, f_len));
}
