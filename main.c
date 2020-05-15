#include "monty.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char* argv[])
{
	stack_t *head;
	FILE* demo = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int count_line = 0;
	char *token;
	char *number = 0;

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

		number = strtok(NULL, "\n\t ");
		printf("%s\n", number);

		function_op(&head, token, count_line);
	}

	free(line);

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

  dprintf(2, "L<%d>: usage: push integer\n", nRead);


  exit(EXIT_FAILURE);
}

/**
 * push - function push
 *
 * @stack: head a pointer to sign string
 * @number: number
 *
 * Return: the result of operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;

	if ((*stack) != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
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
	stack_t *tmp = 0;

	(void) line_number;

	tmp = *stack;
	while(tmp != NULL)
	{
		printf("%d", tmp->n);
		tmp = tmp->next;
	}
}
