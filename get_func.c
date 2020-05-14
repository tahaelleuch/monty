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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	size_t i;
	char *valid_op[] = {"push", "pall", "pint", "pop",
			    "swap", "add", "nop", "end"};
	int len, j = 0;

	len = sizeof(valid_op) / sizeof(valid_op[0]);
	while (j < len)
	{
		if (strcmp(valid_op[j], func) == 0)
			break;
		if (strcmp(valid_op[j], "end") == 0)
			return (0);
		j++;
	}
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
