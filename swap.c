#include "monty.h"
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *aux = NULL;

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
    *stack = (*stack)->next;
    aux = (*stack)->next;

    if (aux)
        aux->prev = (*stack)->prev;

    (*stack)->next = (*stack->prev);
    (*stack)->prev->prev = *stack;
    (*stack)->prev = NULL;
    (*stack)->next->next = aux;
}