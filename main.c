#include "monty.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char* argv[])
{
	stack_t *head;
	FILE* demo;
	char *line = NULL;
	size_t len = 0, inter = 0;
	ssize_t nread;
	char *token;

	if (argc != 2)
	{

		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	demo = fopen(argv[1], O_RDONLY);

	if (demo == NULL)
	{
		dprintf(2, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty_line.demo = demo;

	while ((nread = getline(&line, &len, demo)) != -1);
	{
		/*printf("L%i: usage: push integer\n", len);*/
		nread++;

		token = strtok(str, "\n\t");
		


		/* function_op(head, token, nread); */
	}


}


/**
 * get_op_func - selects the correct function to perform the operation
 *
 * @s: a pointer to sign string
 * Return: the result of operation
 */
void function_op(stack_t *h_stack, char *operation, int nRead)
{
  int i;
  instruction_t ops[] = {
    {"push", push},
    {"pall", pall},
    /*{"*", op_mul},
    {"/", op_div},
    {"%", op_mod},*/
    {NULL, NULL}
  };


  i = 0;
  while (ops[i].opcode)
    {
      
      if (strcmp(*(ops[i]).op, operation) == 0)
	return (ops[i].f(h_stack, nRead));

      i++;

    }

  dprintf(2, "L<%d>: usage: push integer", nRead);


  exit(EXIT_FAILURE);
}

