/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:03:26 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/29 16:00:23 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		is_this_line(char *str);
char	*put_in_line(char *temp, char **line, int size);
char	*ft_join(char *s1, char *s2, int buf_len);
char	*keep_nxt(char *keep);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strclen(const char *str, char c);
int		free_str(char **str);
void	*try_to_malloc(char *dst, char *src, int size);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
#endif
