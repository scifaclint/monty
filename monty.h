#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct global_s - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Error Handling*/
void print_usage_error(void);
void print_file_open_error(const char *filename);
void print_error_and_exit(const char *msg, stack_t **stack);
void handle_malloc_error(stack_t **stack, unsigned int line_number);
void handle_unk_inst(char *opcode, stack_t **stack, unsigned int line_number);
void handle_push_error(stack_t **stack, unsigned int line_number);
void handle_pint_error(unsigned int line_number, stack_t **stack);
void stack_too_short_error(unsigned int line_number, stack_t **stack);

/* MISC functions */
stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void stack_free(stack_t *stack);


/* Main Operation Functions - Mandatory tasks*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* Execution Functions */
void execute_input(stack_t **stack);
void execute(char *opcode, stack_t **stack, unsigned int line_number);


/* Advanced Operation Functions - Advanced tasks */
void sub(stack_t **stack, unsigned int line_number);
void divv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);


#endif /* monty.h */
