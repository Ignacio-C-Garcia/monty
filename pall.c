#include "monty.h"
/**
 * pall - print a linked list
 * @stack: header of dll
 * @line_number: line number
 */
void pall(const stack_t **header, unsigned int line_number)
{
	stack_t *h = *header;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	(void)line_number;
}
