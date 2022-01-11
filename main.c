#include "monty.h"
/**
 * main - main function of monty interpreter
 *
 * @argc: argument counter (must be 2)
 * @argv: argument vector
 * Return: 0 on succes or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int f_desc;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f_desc = open(argv[1], O_RDONLY);
	if (!f_desc)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(f_desc);

	return (0);
}

int read_file(int f_desc)
{
	char buff[1024];

	while (getline(buff, f_desc) != -1)
		printf("buffer: %s\n", buff);

	return (0);
}
