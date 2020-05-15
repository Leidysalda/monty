#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - function push
 *
 * @stack: head a pointer to sign string
 * @line_number: line number
 *
 * Return: the result of operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	(void) line_number;

	new_node = node_end(stack, atoi(monty_line.value));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - function pall
 *
 * @stack: head a pointer to sign string
 * @number: number
 *
 * Return: the result of operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
