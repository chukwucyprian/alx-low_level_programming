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
	if (filename == NULL)
		return (0);

	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		return (0);

	char *buff = malloc((letters + 1) * sizeof(char));

	if (buff == NULL)
	{
		fclose(fp);
		return (0);
	}

	ssize_t count = fread(buff, sizeof(char), letters, fp);

	if (count < 0 || count != letters)
	{
		fclose(fp);
		free(buff);
		return (0);
	}
	buff[letters] = '\0';
	fwrite(buff, sizeof(char), count, stdout);

	fclose(fp);
	free(buff);
	return (count);

