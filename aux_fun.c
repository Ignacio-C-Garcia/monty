#include "monty.h"
/**
 * free_stack - frees all nodes from the stack
 *
 * @head: head node of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}
