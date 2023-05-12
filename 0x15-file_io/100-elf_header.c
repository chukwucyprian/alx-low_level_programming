#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message to stderr.
 * @msg: The error message to print.
 */
void print_error(const char *msg);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: Array containing the command-line arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	Elf32_Ehdr header;
	int i;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
		return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: Cannot open file");
		return 98;
	}

	/* Read ELF header */
	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read < (ssize_t)sizeof(header))
	{
		print_error("Error: Cannot read ELF header");
		close(fd);
		return 98;
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	
	for ( i = 0; i < EI_NIDENT; i++)
		printf(" %02x", header.e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n",
	       (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" :
	       (header.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" :
	       "<unknown>");
	printf("  Data:                              %s\n",
	       (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
	       (header.e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" :
	       "<unknown>");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);

	/* ... Rest of the code ... */

	close(fd);
	return 0;
}

/**
 * print_error - Prints an error message to stderr.
 * @msg: The error message to print.
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
}

