#ifndef MONTY_HEADER
#define MONTY_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Aux Functions */
int read_files(FILE *f_desc, stack_t **header);
void get_func(char *command, unsigned int line_num, stack_t **header);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void free_stack(stack_t *head);

/* END Aux Functions */

/* Monty Functions */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* END Monty Functions*/

#endif

