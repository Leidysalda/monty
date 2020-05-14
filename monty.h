#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdin.h>
#include <stdout.h>
#include <stdrr.h>
#include <sfcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "monty.h"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

size_t print(const stack_t *h);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct function_s - Functions
 * @name: name function
 * @value: integer
 *
 * Description: struct of functions
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct function_s
{
	FILE* demo;
	char *opcode;
        int *value;
} fuction_t;

function_t monty_line;

#endif
