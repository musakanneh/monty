#include "monty.h"

/**
 * add - adds the top two in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * sub - subtracts the top two in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * mul - find product of top 2 in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * divide - divdid top 2 in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * mod- mod of the top 2 in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}
