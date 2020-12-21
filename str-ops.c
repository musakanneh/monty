#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * @stack: doubly linked list
 * @line_number: the number line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	int a = 0, counter = 0;
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		while (temp)
		{
			if (!temp->next)
			{
				a = temp->n;
			}
			counter++;
			temp = temp->next;
		}
		add_dnodeint(stack, a);
		delete_dnodeint_at_index(stack, counter);
	}
}

/**
 * pint - prints out everything in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * check_string - verify if argument is alpha
 * @s: string passed to function
 * Return: integer
 */
int check_string(char *s)
{
	register int str_idx = 0;

	if (!s)
	{
		return (-1);
	}
	if (*s == '-')
	{
		s++;
	}
	while (s[str_idx])
	{
		if (s[str_idx] >= '0' && s[str_idx] <= '9')
		{
			str_idx++;
		}
		else
		{
			return (-1);
		}
	}
	return (1);
}

/**
 * pstr - prints string
 * @stack: doubly linked list
 * @line_number: the line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * pchar - prints character
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack is empty\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
