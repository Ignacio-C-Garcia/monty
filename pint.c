#include "monty.h"
/**
 * pint - print a linked list
 * @stack: header of dll
 * @line_number: line number
 */
void pint(const stack_t **stack, unsigned int line_number)
{

	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	return (0);
}
