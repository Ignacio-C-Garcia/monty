#include "monty.h"
/**
 * num_checker - checks if token is a str of numbers
 * @token: pointer to char
 * @stack: header of dll
 * @line_number: number of line
 */
void num_checker(char *token, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (token[0] == '-')
		i++;
	if (token[i] == '\0')
	{
		free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (token[i])
	{
		if (token[i] >= '0' && token[i] <= '9')
		{
			i++;
			continue;
		}
		else
		{
			free_stack(*stack);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
