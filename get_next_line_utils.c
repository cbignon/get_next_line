/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:03:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/29 16:00:27 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

void	*try_to_malloc(char *dst, char *src, int size)
{
	if (!(dst = malloc(sizeof(char) * size)))
		return ((void*)(unsigned long long)free_str(&src));
	return (dst);
}
