#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_pint_error(line_number, stack);
	}

	printf("%d\n", (*stack)->n);
}
