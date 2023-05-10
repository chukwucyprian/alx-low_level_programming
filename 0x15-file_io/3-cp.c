#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>



#define BUFSIZE 1024

/**
 * main - copies the content of a file to another file
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 97-100 on failure
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, bytes_rd, bytes_wr, close_from, close_to;
	char buf[BUFSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]), exit(98);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	while ((bytes_rd = read(fd_from, buf, BUFSIZE)) > 0)
	{
		bytes_wr = write(fd_to, buf, bytes_rd);
		if (bytes_wr != bytes_rd || bytes_wr == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}
	if (bytes_rd == -1)
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]), exit(98);
	close_from = close(fd_from);
	if (close_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	close_to = close(fd_to);
	if (close_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
	return (0);
}

