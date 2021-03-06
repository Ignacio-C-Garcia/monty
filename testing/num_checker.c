#include "monty.h"
void num_checker(char *token, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	if (!token)
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
	if (token[0] == '-')
		i++;
	if (token[i] == '\0')
	{
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
			fprintf(stderr, "L%u: usage: push integer", line_number);
			exit(-1);
		}
	}
}
