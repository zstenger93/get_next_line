/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:56:25 by zstenger          #+#    #+#             */
/*   Updated: 2022/10/28 09:58:35 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

//get the length of the line (thestr)
size_t	ft_strlen(const char *theline)
{
	int	z;

	z = 0;
	while (theline[z])
		z++;
	return (z);
}

//for calloc to put zeroes on the allocated memory
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	z;

	str = (char *)s;
	z = 0;
	while (z < n)
	{
		str[z] = '\0';
		z++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}

//for getting the '\n' 
char	*ft_strchr(const char *string, int lookfor)
{
	char	*str;

	str = (char *)string;
	while (*str != lookfor && *str != 0)
		str++;
	if (*str == lookfor)
		return (str);
	else
		return (NULL);
}

/*
for taking the buff (line from the source file)
to the buffer and assign it to a temporary pointer
then free the buffer and return the pointer and assign
it to res(resource)
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		z;
	int		j;
	int		fullsize;
	char	*res;

	z = 0;
	fullsize = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (fullsize + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[z] != 0)
	{
		res[z] = s1[z];
		z++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[z] = s2[j];
		z++;
		j++;
	}
	res[fullsize] = 0;
	return (res);
}
