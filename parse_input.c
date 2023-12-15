#include "shell_header.h"

void check_tokens(char **tokens)
{
	if (tokens == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
}

char **parse_input(char *str_input)
{
	int bufferSize = 128, index = 0;
	char *token;
	char **tokens = malloc(bufferSize * sizeof(char *));

	check_tokens(tokens);
	token = strtok(str_input, " \n");
	while (token)
	{
		tokens[index] = strdup(token);
		index++;

		if (index >= bufferSize)
		{
			bufferSize *= 2;
			tokens = realloc(tokens, bufferSize * sizeof(char *));
			check_tokens(tokens);
		}
		token = strtok(NULL, " \n");
	}
	tokens[index] = NULL;
	return (tokens);
}
