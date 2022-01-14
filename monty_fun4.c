#include "monty.h"
/**
 * monty_stack_mode - sets stack to FIFO mode
 *
 * @head: pointer to the address of stack
 * @line_number: line number
 */
void monty_stack_mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	stack_mode = 1;
}

/**
 * monty_queue_mode - sets stack mode to LIFO
 * @head: pointer to the address of the stack
 * @line_number: line number
 */
void monty_queue_mode(stack_t **head, unsigned int line_number)
{
	(void)*head;
	(void)line_number;
	stack_mode = 0;
}
