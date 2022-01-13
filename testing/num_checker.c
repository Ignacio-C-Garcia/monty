#include "monty.h"
void num_checker(char *token, stack_t **stack, unsigned int line_number)
{
    int i = 0;
    if (token[0] == '-')
        i++;
    if (token[i] == '\0')
    {
		    fprintf(stderr, "L%d: usage: push integer", line_number);
		    free_stack(*stack);
		    exit(EXIT_FAILURE);
	    }
    while (token[i])
    {
        if (token[i] < '0' || token[i] > '9')
            continue;
        else
        {
		    fprintf(stderr, "L%d: usage: push integer", line_number);
		    free_stack(*stack);
		    exit(EXIT_FAILURE);
	    }
    }
    printf("%d", atoi(token));
}