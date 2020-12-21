#include "monty.h"

/**
 * push - adds data to the top of the stack
 * breaks string into series of tokens using delimeter
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 *
 * Description: check paraams params variable against input strings
 * then, locate stack beased on the order of input arguements
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	register int num;
	char *params = strtok(NULL, "\n");

	if (check_string(params) == -1)
	{
		fprintf(stderr, "L%u: usage push integer \n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	num = atoi(params);
	if (args.order == 1)
	{
		add_dnodeint(stack, num);
	}
	else
	{
		add_dnodeint_end(stack, num);
	}
}

/**
 * pop - a function to pull data from the top of the stack
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 *
 * Description: delete nodes at index if stack is not empty
 * otherwise, print an error message
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: Can't pop from an empty stack \n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap - a function to swap within the stack
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 *
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	register int temp;

	if ((!*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - returns nothing from stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pall - prints everything in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}
