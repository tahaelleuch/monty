#include "monty.h"
/**
 * pchar - print char
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
