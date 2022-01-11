#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;
    if (*stack)
    {
        *stack = (*stack)->next;
		if (*stack)
            (*stack)->prev = NULL;
        free(head);
    }
    else
    {
        printf("L%u: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
}
