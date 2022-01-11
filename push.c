#include "monty.h"
/**
 * push - add a node at the beginning of dll
 * @stack: header of dll
 * @n: value number of node
 */
void push(stack_t **stack, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		{
			printf("Error: malloc failed");
			exit(EXIT_FAILURE);
		}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
