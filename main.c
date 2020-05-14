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

		strtok(str, "\n\t");
		exit("EXIT_FAILURE");
	}


}
