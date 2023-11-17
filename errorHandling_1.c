#include "monty.h"

/**
 * print_usage_error - Print usage error message and exit
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_file_open_error - Print file open error message and exit
 * @filename: Name of the file that couldn't be opened
 */
void print_file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}


/**
 * print_error_and_exit - prints an error message and exits the program
 * @msg: error message to be printed
 * @stack: pointer to the top of the stack
 */
void print_error_and_exit(const char *msg, stack_t **stack)
{
	fprintf(stderr, "Error: %s\n", msg);
	stack_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * handle_malloc_error - Handles the "malloc failed" error.
 * @stack: pointer to the top of the stack
 * @line_number: current line number of the opcode in the Monty file
 */
void handle_malloc_error(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	fprintf(stderr, "Error: malloc failed\n");
	stack_free(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
