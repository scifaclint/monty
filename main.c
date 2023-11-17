#include "monty.h"

glob_t glob;

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
		print_usage_error();

	glob.file = fopen(argv[1], "r");
	if (glob.file == NULL)
	{
		print_file_open_error(argv[1]);
	}

	execute_input(&stack);
	fclose(glob.file);
	free(glob.line);
	stack_free(stack);
	exit(EXIT_SUCCESS);
}
