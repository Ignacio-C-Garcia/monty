#include "mondty.h"
/**
 * monty_mod - sets the module of first 2 nodes of stack node2 % node 1
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_number);
}
