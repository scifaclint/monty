#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @stack: pointer to pointer of the top of the stack
 * @value: value to be added to the new node
 *
 * Return: pointer to the newly added node
 */
stack_t *add_node(stack_t **stack, const int value)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		print_error_and_exit("malloc failed", stack);
	}

	newNode->n = value;
	newNode->prev = NULL;

	if (*stack == NULL)
		newNode->next = NULL;
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	*stack = newNode;

	return (newNode);
}
