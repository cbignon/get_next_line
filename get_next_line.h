/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:42:28 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/18 15:26:00 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_end_of_line(char *s, int size);
int		put_in_line(char *temp, char **line, int size);
char	*keep_in_temp(char *temp, char *buf);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t number, size_t size);
size_t	ft_strclen(const char *str, char c);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
