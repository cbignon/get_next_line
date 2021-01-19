/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:42:49 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/19 11:14:29 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_end_of_line(char *s, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (s[x] == '\n')
			return (1);
		if (s[x] == '\0')
			return (0);
		x++;
	}
	return (-1);
}

int		put_in_line(char *temp, char **line, int size)
{
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		return (-1);
	(*line)[size] = '\0';
	*line = ft_memcpy(*line, temp, size);
	return (0);
}

char	*keep_in_temp(char *temp, char *buf)
{
	size_t		biglen;
	size_t		x;
	size_t		y;
	char		*big_s;

	if (temp == NULL && buf == NULL)
		return (NULL);
	if (*buf == 0)
		biglen = ft_strclen((char*)temp, 0);
	else
		biglen = (ft_strclen((char*)temp, 0) + BUFFER_SIZE);
	if (!(big_s = (char*)malloc(sizeof(char) * (biglen + 1))))
		return (NULL);
	x = -1;
	while (++x < ft_strclen((char*)temp, 0))
		big_s[x] = temp[x];
	y = 0;
	while (x < biglen)
		big_s[x++] = buf[y++];
	big_s[x] = '\0';
	return (big_s);
}

int		get_next_line(int fd, char **line)
{
	static char	*temp;
	static char	*buf;
	int			line_len;
	int			in_buf;

	if (!line || !fd || BUFFER_SIZE <= 0)
		return (-1);
	if (!buf)
	{
		if (!(buf = ft_calloc(BUFFER_SIZE, 1)))
			return (-1);
	}
	if (!temp)
	{
		if (!(temp = ft_calloc(BUFFER_SIZE + 1, 1)))
			return (-1);
	}
	in_buf = 0;
	while (in_buf >= 0)
	{
		in_buf = read(fd, buf, BUFFER_SIZE);
		temp = keep_in_temp(temp, buf);
		line_len = ft_strclen(temp, 0);
		while (ft_end_of_line(temp, line_len) == -1)
		{
			in_buf = read(fd, buf, BUFFER_SIZE);
			if (in_buf == 0)
			{
				put_in_line(temp, line, line_len);
				free(temp);
				temp = NULL;
				return (0);
			}
			temp = keep_in_temp(temp, buf);
			line_len = ft_strclen(temp, 0);
		}
		if (ft_end_of_line(temp, line_len) == 1)
		{
			ft_memset(buf, 0, BUFFER_SIZE);
			line_len = ft_strclen(temp, '\n');
			put_in_line(temp, line, line_len);
			temp = keep_in_temp(temp + (line_len + 1), buf);
			free(buf);
			buf = NULL;
			return (1);
		}
	}
	free(temp);
	temp = NULL;
	return (-1);
}
