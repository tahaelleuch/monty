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
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		if (!isascii(temp->n) || temp->n == 0)
			break;
		putchar(temp->n);
		temp = temp->prev;
	}
	putchar('\n');
}
