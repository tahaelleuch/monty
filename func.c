#include "monty.h"
FILE *m_file;
char *func;
/**
 * pop - removes the top element of the stack.
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
}
