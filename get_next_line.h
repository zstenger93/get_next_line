/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:46:09 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 14:21:34 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_remove_line(char *buffer);
char	*ft_return_line(char *buffer);
char	*ft_free_buffer(char *buffer, char *buff);
char	*ft_read_file(int fd, char *resource);

//extra functions
char	*ft_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *string, int lookfor);
size_t	ft_strlen(const char *theline);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif