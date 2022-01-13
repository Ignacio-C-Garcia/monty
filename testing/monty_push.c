#include "monty.h"
/**
 * monty_push - add a node at the beginning of dll
 * @stack: header of dll
 * @line_number: value number of node
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;
	int value;
	(void)line_number;

	token = strtok(NULL, " ");
	if (!token || ((token[0] < '0' || token[0] > '9') && token[0] != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
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
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	/*
	 * free(token);
	 */
}
