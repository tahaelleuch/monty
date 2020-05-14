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
/**
 * swap - swaps the top two elements of the stack.
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int temp;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}
/**
 * add- adds the top two elements of the stack.
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	 stack_t *head;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n += head->n;
	(*stack)->prev = NULL;
	free(head);
}
