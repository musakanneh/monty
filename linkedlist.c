#include "monty.h"

/**
 * delete_dnodeint_at_index - Delete node at index
 * @head: Doubly linked list
 * @index: index
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

	if (!head || !*head)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
		{
			(*head)->prev = NULL;
		}
		free(temp);
		return (1);
	}
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (index >= i)
	{
		return (-1);
	}
	temp = *head;
	while (temp && temp->next)
	{
		if (index == 0)
			break;
		index--;
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	return (1);
}

/**
 * free_dlistint - frees doubly linked list
 * @head: doubly linked list
 * Return: Nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}

/**
 * stack_size - shows size of stack
 * @h: doubly linked list
 * Return: Size of stack
 */
size_t stack_size(const stack_t *h)
{
	size_t c = 0;

	while (h)
	{
		c++;
		h = h->next;
	}
	return (c);
}

/**
 * print_dlistint - prints doubly linked list
 * @h: doubly linked list
 * Return: Size of linked list
 */
size_t print_dlistint(const stack_t *h)
{
	size_t character = 0;

	while (h)
	{
		character++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (character);
}

/**
 * add_dnodeint - adds a node at the beginning
 * @head: doubly linked list
 * @n: data of a node
 * Return: Doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleaner();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}
