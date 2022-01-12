#include "monty.h"
/**
 * monty_nop - The opcode nop doesn’t do anything.
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pint - print first node of a linked list
 * @stack: header of dll
 * @line_number: line number
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
	fprintf("L%u: can't pint, stack empty", line_number);
	exit(EXIT_FAILURE);
	}
}

