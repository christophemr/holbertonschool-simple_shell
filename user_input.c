#include "shell_header.h"

/**
 * get_user_input - function to read a line of input from the standard input
 * Return: the user's input
 */

char *get_user_input()
{
	char *input = NULL;
	size_t size = 0;
	ssize_t inputSize = 0;

	inputSize = getline(&input, &size, stdin);

	if (inputSize == -1)
	{
		free(input);
		if (feof(stdin))
			return (NULL);
		if (isatty(fileno(stdin)))
			fprintf(stderr, "Closing Shell\n");
		exit(EXIT_FAILURE);
	}
	if (inputSize > 0 && input[inputSize - 1] == '\n')
		input[inputSize - 1] = '\0';

	return (input);
}
