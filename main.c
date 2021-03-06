#include "monty.h"
int stack_mode;
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

	stack_mode = 1;

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
	unsigned int line_num = 0;

	while (getline(&buff, &len, f_desc) != -1)
	{
		line_num++;
		if (buff[strlen(buff) - 1] == '\n')
			buff[strlen(buff) - 1] = '\0';

		command = strtok(buff, " ");
		if (!command)
		{
			free(buff);
			buff = NULL;
			continue;
		}
		if (command[0] == '#')
		{
			free(buff);
			buff = NULL;
			continue;
		}
		get_func(command, line_num, header);
		free(buff);
		buff = NULL;
	}
	free(buff);
	command = NULL;
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
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack_mode},
		{"queue", monty_queue_mode},
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
		free_stack(*header);
		command = NULL;
		exit(EXIT_FAILURE);
	}
}

