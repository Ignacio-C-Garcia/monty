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
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * monty_sub - sub value of first 2 nodes of dll
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - divides value of first 2 nodes of dll
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies value of first 2 nodes of dll
 * @stack: header of the stack
 * @line_number: value number of node
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	monty_pop(stack, line_number);
}
