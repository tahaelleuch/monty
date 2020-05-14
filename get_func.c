#include "monty.h"
/**
 * get_func - get the specefic opcodes
 * @func: the function to check
 * @nb_number: number of current line
 * @stack: the header of the stack
 * Return: 1 if sucess else 0
*/
int get_func(char *func, unsigned int nb_number, stack_t **stack)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	size_t i;

	for (i = 0; function->opcode != NULL; i++)
	{
		if (strcmp((function + i)->opcode, func) == 0)
		{
			(function + i)->f(stack, nb_number);
			return (1);
		}
	}
	return (0);
}