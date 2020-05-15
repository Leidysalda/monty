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
	int count_line = 0;
	char *number = 0;
	ssize_t nread;
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

		token = strtok(line, "\n\t");

		number = strtok(NULL, "\n\t ");
		printf("%s", number);

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

  dprintf(2, "L<%d>: usage: push integer", nRead);


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
	(void) stack;
	(void) line_number;
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
	(void) stack;
	(void) line_number;
}
