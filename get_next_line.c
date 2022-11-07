/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:48:07 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/06 16:57:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

/*
the buffer stores the information until you free it
if the file descriptor, the file being read is less than 0 or the buffer
size is equal or smaller than zero, return null
read the file
take the line when \n found
remove the line from the buffer
return the line
*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	line = ft_return_line(buffer);
	buffer = ft_remove_line(buffer);
	return (line);
}

/*
if no resource then allocate one block of memory with one byte on it
thi is against seg faults caused by entering the function with nothing
to read
allocating the memory for the buffer
assigning the value of the current bytes being read
while its bigger than 0 and not end of line, read
buffer[] set to 0 to prevent leaks
assign the resource to the line got from the buffer and when the new
line found stop reading, free the bufer and return the resource
*/
char	*ft_read_file(int fd, char *resource)
{
	char	*buffer;
	int		current_byte_being_read;

	if (!resource)
		resource = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	current_byte_being_read = 1;
	while (current_byte_being_read > 0)
	{
		current_byte_being_read = read(fd, buffer, BUFFER_SIZE);
		buffer[current_byte_being_read] = 0;
		resource = ft_free_buffer(resource, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resource);
}

/*
while buffer[] and its not a new line, count
if no buffer, free buffer, return null (to aovid leaks)
allocate memory for the length of file - length of first line + 1
assign the buffer to the line, free the buffer and return the line
*/
char	*ft_remove_line(char *buffer)
{
	int		z;
	int		s;
	char	*file_minus_line;

	if (!buffer)
		return (NULL);
	z = 0;
	while (buffer[z] != '\0' && buffer[z] != '\n')
		z++;
	if (buffer[z] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	file_minus_line = malloc(sizeof(char) * ((ft_strlen(buffer) - z) + 1));
	if (!file_minus_line)
		return (NULL);
	z++;
	s = 0;
	while (buffer[z] != '\0')
		file_minus_line[s++] = buffer[z++];
	file_minus_line[s] = '\0';
	free(buffer);
	return (file_minus_line);
}

/*
no line -> return
go to the end of the line
malloc the line line +2 for \n and terminatign null
assign the buffer to the line
add the \n to the end of the line and
return the line
*/
char	*ft_return_line(char *buffer)
{
	char	*line;
	int		z;

	z = 0;
	if (!buffer[z])
		return (NULL);
	while (buffer[z] && buffer[z] != '\n')
		z++;
	line = malloc(sizeof(char) * (z + 2));
	z = 0;
	while (buffer[z] && buffer[z] != '\n')
	{
		line[z] = buffer[z];
		z++;
	}
	if (buffer[z] && buffer[z] == '\n')
		line[z++] = '\n';
	line[z] = '\0';
	return (line);
}

/*
takes the buff to the buffer and assign the buffer to a pointer,
frees the buffer and retruns the pointer
*/
char	*ft_free_buffer(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}
