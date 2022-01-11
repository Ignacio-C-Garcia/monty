#include "monty.h"

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
        printf("L%u: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
    
    (void)line_number;
}

/**
 * push - add a node at the beginning of dll
 * @stack: header of dll
 * @n: value number of node
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	/*char *token;
	int value;*/
	(void)line_number;

	/* We have to check if token is empty or NaN
	if (!(token = strtok(NULL, " ")))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
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

	/*free(token);*/
}

void swap(stack_t **stack, unsigned int line_number)
{
    unsigned int aux;

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
    aux = (*stack)->n;

    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = aux;

    (void)line_number;
}

/**
 * pint - print a linked list
 * @stack: header of dll
 * @line_number: line number
 */
void pint(const stack_t **stack, unsigned int line_number)
{

	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print a linked list
 * @stack: header of dll
 * @line_number: line number
 */
void monty_pall(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
