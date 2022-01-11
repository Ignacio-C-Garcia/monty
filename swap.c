#include "monty.h"
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
}