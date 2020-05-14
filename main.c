#include "monty.h"
FILE *m_file;
char *func = NULL;
/**
 * main - The monty program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	char *buf = NULL;
	size_t len = 0;
	unsigned int nb_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m_file = fopen(argv[1], "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &len, m_file) != -1)
	{
		func = strtok(buf, " \n\t");
		if (func == NULL || func[0] == '#')
			continue;
		if (get_func(func, nb_number, &stack) == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", nb_number, func);
			fclose(m_file);
			free_list(stack);
			free(func);
			exit(EXIT_FAILURE);
		}
		nb_number++;
	}
	free_list(stack);
	free(buf);
	fclose(m_file);
	exit(EXIT_SUCCESS);
}

