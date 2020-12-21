#include "monty.h"

/**
 * cleaner - cleans stack
 */
void cleaner(void)
{
	free_dlistint(args.stack);
	if (args.file)
	{
		fclose(args.file);
	}
}

/**
 * monty - custom interpretor
 * Return: Nothing
 */
void monty(void)
{
	char line[128];

	args.file = fopen(args.argv[1], "r");
	if (args.file != NULL)
	{
		while (fgets(line, sizeof(line), args.file) != NULL)
		{
			args.counter++;
			args.line = line;
			caller();
		}
		fclose(args.file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", args.argv[1]);
		cleaner();
		exit(EXIT_FAILURE);
	}
}

/**
 * caller - caller
 */
void caller(void)
{
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL}};
	int i = 0;
	char *op = NULL;

	op = strtok(args.line, " \n");
	if (!op || *op == '#')
		return;
	while (ins[i].opcode && op)
	{
		if (!strcmp(op, ins[i].opcode))
		{
			ins[i].f(&(args.stack), args.counter);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%ld: unknown instruction %s\n", args.counter, op);
	cleaner();
	exit(EXIT_FAILURE);
}

/**
 * rotl - rotates stack to the top
 * @stack: doubly linked list
 * @line_number: the line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack && (*stack)->next)
	{
		add_dnodeint_end(stack, (*stack)->n);
		delete_dnodeint_at_index(stack, 0);
	}
}

/**
 * add_dnodeint_end - adds a node at the end of a doubly linked list
 * @head: doubly linked list
 * @n: data for a node
 * Return: doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = NULL;
	stack_t *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
	return (new_node);
}
