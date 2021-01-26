/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:03:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/26 10:59:33 by cbignon          ###   ########.fr       */
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

char	*ft_join(char *s1, char *s2, int buf_len)
{
	size_t		x;
	size_t		y;
	size_t		len1;
	char		*big_s;

	len1 = 0;
	if (s1 == NULL)
		big_s = malloc(sizeof(char) * (buf_len + 1));
	else
	{
		len1 = ft_strclen((char*)s1, 0);
		if (!(big_s = (char*)malloc(sizeof(char) * (buf_len + len1) + 1)))
			return (NULL);
	}
	x = -1;
	while (++x < len1)
		big_s[x] = s1[x];
	y = 0;
	while (x < (buf_len + len1))
		big_s[x++] = s2[y++];
	big_s[x] = '\0';
	if (s1)
		free(s1);
	return (big_s);
}
