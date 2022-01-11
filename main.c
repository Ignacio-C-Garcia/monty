#include "main.h"
/**
 * main - main function of monty interpreter
 *
 * @argc: argument counter (must be 2)
 * @argv: argument vector
 * Return: 0 on succes or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int f_desc = NULL;

	if (argc != 2)
	{
		fprint(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE)
	}

	f_desc = open(argc[1], R_ONLY);
	if (!f_desc)
	{
		fprint(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(f_desc);

	return (0);
}

int read_file(int f_desc)
{
	char buff[1024];

	getline(buff, 1024, f_desc);
	
}
