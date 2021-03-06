#include "monty.h"
/**
 * monty_pop - removes first node of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack)
	{
	*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

}

/**
 * monty_push - add a node at the beginning of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	char *token;
	(void)line_number;

	token = strtok(NULL, " ");
	num_checker(token, stack, line_number);

	if (stack_mode == 1)
		add_stack(stack, atoi(token), line_number);

	if (stack_mode == 0)
		add_stack_end(stack, atoi(token), line_number);
}
/**
 * monty_swap - swap two frist nodes of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	unsigned int tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

}

/**
 * monty_pall - print a linked list
 * @header: header of dll
 * @line_number: line number
 */
void monty_pall(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * monty_add - add value of first 2 nodes of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	monty_pop(stack, line_number);
}
