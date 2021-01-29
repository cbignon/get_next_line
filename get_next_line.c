/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:02:46 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/28 14:28:53 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_this_line(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*keep_nxt(char *keep)
{
	char	*nxt;
	size_t	o_len;
	size_t	n_len;
	size_t	i;
	size_t	j;

	o_len = ft_strclen(keep, 0);
	n_len = ft_strclen(keep, '\n');
	i = 0;
	while (i < n_len + 1)
		i++;
	if (n_len >= o_len)
		return (keep);
	if (!(nxt = malloc(sizeof(char) * (o_len - n_len) + 1)))
		return ((void*)(unsigned long long)free_str(&keep));
	j = 0;
	while (j < (o_len - n_len))
	{
		nxt[j] = keep[i];
		i++;
		j++;
	}
	nxt[j] = '\0';
	free(keep);
	return (nxt);
}

char	*put_in_line(char *temp, char **line, int size)
{
	int	x;

	x = 0;
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		return ((void*)(unsigned long long)free_str(&temp));
	(*line)[size] = '\0';
	while (x < size)
	{
		(*line)[x] = temp[x];
		x++;
	}
	return (*line);
}

int		get_next_line(int fd, char **line)
{
	int			in_buf;
	static char	*keep;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !(buf = malloc(BUFFER_SIZE)))
		return (-1);
	ft_memset(buf, 0, BUFFER_SIZE);
	in_buf = 1;
	while (in_buf != 0 && is_this_line(keep) == 0)
	{
		if ((in_buf = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (free_str(&keep) - 1);
		}
		keep = ft_join(keep, buf, in_buf);
	}
	free(buf);
	*line = put_in_line(keep, line, ft_strclen(keep, '\n'));
	keep = keep_nxt(keep);
	if (in_buf == 0)
		return (free_str(&keep));
	return (1);
}
