#include "monty.h"

/**
 * push - a function to add data to the top of the stack
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 * 
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
    
}

/**
 * pop - a function to pull data from the top of the stack
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 * 
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{

}

/**
 * swap - a function to swap within the stack
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 * 
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
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
