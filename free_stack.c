#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: the header of the stack
*/
void free_list(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack != NULL)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}
