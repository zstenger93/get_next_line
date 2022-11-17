#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char	*get_next_line(int fd);


int main(void)
{
	char *line;
	char *name = "read_error.txt";
	char *other = "lines_around_10.txt";
	int fd = open(name, O_RDONLY);
	int fd2 = open(other, O_RDONLY);


	line = get_next_line(fd);
	printf("1. %s\n", line);
	free(line);
	

	close(fd);

	

	line = get_next_line(fd);
	printf("2. %s\n", line);
	free(line);
	
	fd = open(name, O_RDONLY);

	// if (BUFFER_SIZE > 0) {
	// 	char *temp;
	// 	do
	// 	{
	// 		temp = get_next_line(fd);
	// 		free(temp);
	// 	} while (temp != NULL);
	// }
	// close(fd);

	line = get_next_line(fd);
	printf("3. %s\n", line);
	free(line);
	
	
	fd = open(name, O_RDONLY);
	
	line = get_next_line(fd);
	printf("4. %s\n", line);
	free(line);
	
	line = get_next_line(fd2);
	printf("5. %s\n", line);
	free(line);
	

	close(fd2);

	line = get_next_line(fd);
	printf("6. %s\n", line);
	free(line);
	
	fd2 = open(other, O_RDONLY);
	
	line = get_next_line(fd);
	printf("7. %s\n", line);
	free(line);
	
	line = get_next_line(fd2);
	printf("8. %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("8. %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("8. %s\n", line);
	free(line);

	close(fd);
	close(fd2);

return (0);

}