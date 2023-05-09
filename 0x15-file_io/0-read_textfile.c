#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the STDOUT
 * @filename: the name of the file to read
 * @letters: the number of letters to read from the file
 *
 * Return: the actual number of letters read and printed, or 0 on error
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t y;
	ssize_t x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	x = read(fd, buff, letters);
	y = write(STDOUT_FILENO, buff, x);

	free(buff);
	close(fd);
	return (y);
}

