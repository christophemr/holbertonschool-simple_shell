#include "shell_header.h"

char *get_user_input()
{
	char *input = NULL;
	size_t size = 0;
	ssize_t inputSize = 0;

	inputSize = getline(&input, &size, stdin);

	if (inputSize == -1)
	{
		if (isatty(fileno(stdin)))
			fprintf(stderr, "Closing Shell\n");
		exit(EXIT_FAILURE);
	}
	return (input);
}
