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
	FILE *f_desc;
	stack_t *header = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f_desc = fopen(argv[1], "r");
	if (!f_desc)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_files(f_desc, &header);

	fclose(f_desc);
	free_stack(header);
	return (0);
}
/**
 * read_files - read each line of file and call get_func
 * @f_desc: file descriptor
 * @header: header of dll
 * Return: 0 on success
 */
int read_files(FILE *f_desc, stack_t **header)
{
	char *buff, *command;
	size_t len = 1024;
	unsigned int line_num = 1;

	while (getline(&buff, &len, f_desc) != -1)
	{
		if (buff[strlen(buff) - 1] == '\n')
			buff[strlen(buff) - 1] = '\0';
		if (len == 1)
			exit(0);
		command = strtok(buff, " ");
		if (!command)
			break;
		/*printf("command: %s %ld\n", command, strlen(command));*/
		get_func(command, line_num, header);
		line_num++;

		free(buff);
		buff = NULL;
	}
	free(buff);

	return (0);
}
/**
 * get_func - call a function if the line is a command
 * @command: firs word of the line
 * @line_num: line number of de file
 * @header: header of dll
 */
void get_func(char *command, unsigned int line_num, stack_t **header)
{
	int idx;

	instruction_t instruction_list[] = {
		{"push", monty_push},
		{"pop", monty_pop},
		{"pall", monty_pall},
		{"swap", monty_swap},
		{"pint", monty_pint},
		{"nop", monty_nop},
		{"add", monty_add},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{NULL, NULL}

	};

	for (idx = 0; instruction_list[idx].opcode; idx++)
	{
		if (strncmp(command, instruction_list[idx].opcode, strlen(command)) == 0)
		{
			instruction_list[idx].f(header, line_num);
			break;
		}
	}
	/* command not found */
	if (instruction_list[idx].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, command);
		exit(EXIT_FAILURE);
	}
}

