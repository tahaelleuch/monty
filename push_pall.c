#include "monty.h"
FILE *m_file;
char *func;
/**
 * push - add an integer in the stack
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *s_number = NULL;
	stack_t *new_st;

	s_number = strtok(NULL, " \n\t");
	if (s_number == NULL || check_for_int(s_number) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	new_st = malloc(sizeof(stack_t));
	if (new_st == NULL)
	{
		fprintf(stderr, "USAGE: malloc failed\n");
		free_list(*stack);
		free(func);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
	new_st->n = atoi(s_number);
	new_st->next = *stack;
	new_st->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_st;
	*stack = new_st;
}

/**
 * check_for_int - check if a string is digit
 * @s: string to check
 * Return: 1 if digit else 0
*/
int check_for_int(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (s[i] > '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

/**
 * pall - print all the values on the stack
 * @stack: the header of the stack
 * @line_number: the current line number
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *list;

	list = *stack;
	while (list != NULL)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}
