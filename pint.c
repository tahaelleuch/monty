#include "monty.h"
FILE *m_file;
char *func;
/**
 * pint - print the header of the stack
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
}
