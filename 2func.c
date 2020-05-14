#include "monty.h"
FILE *m_file;
char *func;
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(head);
}
