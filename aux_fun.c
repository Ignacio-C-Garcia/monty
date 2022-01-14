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

/**
 * add_stack - adds a new node to the beggining of the stack
 *
 * @head: double linekd list
 * @n: value of new node
 * @line_number: number of line of the instruction
 * Return: adress of new node or NULL if failed
 */
void add_stack(stack_t **head, const int n, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp_node = *head;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		fprintf(stderr, "L%d: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = tmp_node;

	if (tmp_node)
		tmp_node->prev = new_node;

	*head = new_node;
}

/**
 * add_stack_end - adds a node at the end of the stack
 *
 * @head: head of the double linked list
 * @n: value for new node
 * @line_number: number of line of the instruction
 * Return: head of the list
 */
void add_stack_end(stack_t **head, const int n, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp_node = *head;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		fprintf(stderr, "L%d: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp_node && tmp_node->next)
		tmp_node = tmp_node->next;

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (tmp_node)
	{
		new_node->prev = tmp_node;
		tmp_node->next = new_node;
	}
	else
		*head = new_node;

}

/**
 * num_checker - checks if token is a str of numbers
 * @token: pointer to char
 * @stack: header of dll
 * @line_number: number of line
 */
void num_checker(char *token, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (token[0] == '-')
		i++;
	if (token[i] == '\0')
	{
		free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (token[i])
	{
		if (token[i] >= '0' && token[i] <= '9')
		{
			i++;
			continue;
		}
		else
		{
			free_stack(*stack);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
