#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		stack_too_short_error(line_number, stack);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
