/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:03:26 by cbignon           #+#    #+#             */
/*   Updated: 2021/01/29 10:53:19 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		is_this_line(char *str);
size_t	ft_strclen(const char *str, char c);
char	*ft_join(char *s1, char *s2, int buf_len);
void	*ft_memset(void *s, int c, size_t n);
char	*keep_nxt(char *keep);
void	*ft_memset(void *s, int c, size_t n);
char	*put_in_line(char *temp, char **line, int size);
int		free_static(char *keep);
void	*malloc_fail(char *str);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
