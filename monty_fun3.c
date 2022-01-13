#include "monty.h"
/**
 * monty_mod - sets the module of first 2 nodes of stack node2 % node 1
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 32 && (*stack)->n >127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
