/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:57:18 by zstenger          #+#    #+#             */
/*   Updated: 2022/10/28 11:11:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
//# define	BUFFER_SIZE	42
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);

char	*ft_remove_line(char *buffer);
char	*ft_return_line(char *buffer);
char	*ft_free_buffer(char *buffer, char *buff);
char	*ft_read_file(int fd, char *resource);

//extra functions
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int lookfor);
size_t	ft_strlen(const char *theline);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif