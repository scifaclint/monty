#include "monty.h"

/**
 * stack_free - frees a stack_t list
 * @stack: pointer to the top of the stack
 */
void stack_free(stack_t *stack)
{
	stack_t *current;

	for (current = stack; current != NULL; current = stack)
	{
		stack = stack->next;
		free(current);
	}
}
