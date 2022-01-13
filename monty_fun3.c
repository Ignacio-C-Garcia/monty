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
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
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
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * monty_pstr - prits the stack as a string
 * @stack: header of the stack
 * @line_number: number of line
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp)
	{
		if (tmp->n < 127 && tmp->n > 0)
			printf("%c", tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	printf("\n");
}

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *head;
	(void)line_number;

	head = *stack;
	tail = *stack;

	while (tail->next)
		tail = tail->next;
	
	head->next->prev = NULL;
	head->next = NULL;

	head->prev = tail;
	tail->next = head;


}
















