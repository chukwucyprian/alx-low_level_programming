#include "main.h"


/**
 * append_text_to_file - function that appends text to the end of a file
 * @filename:pointer to name of the file to which text is to be appended
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int z, x, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	z = open(filename, O_WRONLY | O_APPEND);
	x = write(z, text_content, len);

	if (z == -1 || x == -1)
		return (-1);

	close(z);

	return (1);
}

