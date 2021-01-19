/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:43:05 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/19 13:58:49 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		x;
	char		*dest_tmp;
	const char	*src_tmp;

	x = 0;
	dest_tmp = (char*)dest;
	src_tmp = (const char*)src;
	if (dest_tmp != NULL || src_tmp != NULL)
	{
		while (x < n)
		{
			dest_tmp[x] = src_tmp[x];
			x++;
		}
	}
	return (dest);
}

size_t	ft_strclen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*st;

	i = 0;
	st = (char*)s;
	while (i < n)
	{
		st[i] = c;
		i++;
	}
	return ((void*)s);
}

void	*ft_calloc(size_t number, size_t size)
{
	char	*to_allocate;
	size_t	x;

	if (!(to_allocate = malloc(size * number)))
		return (NULL);
	x = 0;
	while (x < (size * number))
	{
		to_allocate[x] = 0;
		x++;
	}
	return (to_allocate);
}

int		free_static(char *temp, char *buf)
{
	free(temp);
	temp = NULL;
	free(buf);
	buf = NULL;
	return (0);
}