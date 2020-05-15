#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - check the code for Holberton School students.
 * @argc: argumentos
 * @argv: Count arguments
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	FILE *demo = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int count_line = 0;
	char *token;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	demo = fopen(argv[1], "r");

	if (demo == NULL)
	{
		dprintf(2, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, demo)) != -1)
	{
		count_line++;

		token = strtok(line, "\n\t ");

		if (!token)
		{
			dprintf(2, "L%d: usage: push integer\n", count_line);
			exit(EXIT_FAILURE);
		}

		monty_line.value = strtok(NULL, "\n\t ");

		printf("%s\n", monty_line.value);


		if (monty_line.value == NULL)
		{
			dprintf(2, "L%d: usage: push integer\n", count_line);
			exit(EXIT_FAILURE);
		}
		function_op(&head, token, count_line);
	}
	free_list(&head);

	return (EXIT_SUCCESS);
}

/**
 * get_op_func - selects the correct function to perform the operation
 *
 * @h_stack: head a pointer to sign string
 * @operation: operation
 * @nRead: number
 *
 * Return: the result of operation
 */
void function_op(stack_t **h_stack, char *operation, int nRead)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};


	i = 0;
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, operation) == 0)
		{
			ops[i].f(h_stack, nRead);
			return;
		}
		i++;
	}

	dprintf(2, "L%d: usage: push integer\n", nRead);


	exit(EXIT_FAILURE);
}


/**
 * free_list - free list
 *
 * @head: head a pointer to sign string
 *
 * Return: the result of operation
 */

void free_list(stack_t **head)
{
	stack_t *tmp = NULL;

	if ((*head) == NULL)
	{
		return;
	}

	while ((*head) != NULL)
	{
		tmp = (**head).next;
		free(tmp);
		(*head) = tmp;
	}
}

/**
 * node_end - function node_end
 *
 * @stack: head a pointer to sign string
 * @n: number
 *
 * Return: the result of operation
 */
stack_t *node_end(stack_t **stack, int n)
{
	stack_t *new_node = NULL;

	if (stack == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;

	return (*stack);
}
