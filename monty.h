#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments - Values to be accessed by various functions
 * @argv: Name of the executable
 * @counter: counts number of lines
 * @line: input line
 * @stack: doubly linked list
 * @file: file
 * @order: FIFO or LIFO
 */
typedef struct arguments
{
	char **argv;
	ssize_t counter;
	char *line;
	stack_t *stack;
	FILE *file;
	int order;
} args_t;

/* str-ops functions start */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
/* str-ops functions end*/

/* opcodes functions start */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/* opcodes functions end*/

/* interpreter functions start */
void monty(void);
void caller(void);
void cleaner(void);
stack_t *add_dnodeint_end(stack_t **head, const int n);
/* interpreter functions end*/

/* interpreter-ii functions start */
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
/* interpreter-ii functions end*/

/* math-ops functions start */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
/* math-ops functions end*/

/* linkedlist functions start */
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(stack_t *head);
size_t stack_size(const stack_t *h);
int check_string(char *s);
/* linkedlist functions end*/

extern args_t args;

#endif /* ifndef MONTY_H*/
