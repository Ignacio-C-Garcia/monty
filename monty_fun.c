#include "monty.h"
/**
 * monty_pop - removes first node of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack)
	{
	*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		printf("L%u: can't pint, stack empty", line_number);
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
	stack_t *new_node;
	/*
	*char *token;
	*int value;
	*/
	(void)line_number;

	/*
	* We have to check if token is empty or NaN
	*if (!(token = strtok(NULL, " ")))
	*{
	*	fprintf(stderr, "L%d: usage: push integer", line_number);
	*	exit(EXIT_FAILURE);
	*}
	*value = atoi(token);
	*/
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(strtok(NULL, " "));
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	/*
	 * free(token);
	 */
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
		printf("L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		printf("L%u: can't swap, stack too short", line_number);
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
	if (!*stack)
	{
		printf("L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		printf("L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	monty_pop(stack, line_number);
}

