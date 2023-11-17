#include "monty.h"

/**
 * handle_unk_inst - handles unknown instruction case
 * @opcode: unknown opcode
 * @line_number: line number of the opcode
 * @stack: pointer to the top of the stack
 */
void handle_unk_inst(char *opcode, stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	stack_free(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}

/**
 * handle_push_error - handles push error
 * @line_number: line number of the opcode
 * @stack: pointer to the top of the stack
 */
void handle_push_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	stack_free(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}

/**
 * handle_pint_error - handles push error
 * @line_number: line number of the opcode
 * @stack: pointer to the top of the stack
 */
void handle_pint_error(unsigned int line_number, stack_t **stack)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free(glob.line);
	stack_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * stack_too_short_error - handles push error
 * @line_number: line number of the opcode
 * @stack: pointer to the top of the stack
 */
void stack_too_short_error(unsigned int line_number, stack_t **stack)
{
	(void) *stack;
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free(glob.line);
	stack_free(*stack);
	exit(EXIT_FAILURE);
}
