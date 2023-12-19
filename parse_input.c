#include "shell_header.h"

/**
 * check_tokens - Checks the allocation of memory for tokens
 * @tokens: Array of strings representing parsed input tokens
 */

void check_tokens(char **tokens)
{
	if (tokens == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
}

/**
 * parse_input - Parses input string into an array of tokens
 *@str_input: Input string to be parsed
 * Return: Array of tokens representing the parsed input
 */

char **parse_input(char *str_input)
{
	int bufferSize = 128, index = 0;
	char *token;
	char **tokens = malloc(bufferSize * sizeof(char *));

	check_tokens(tokens);
	if (str_input == NULL || *str_input == '\0')
	{
		free(tokens);
		return (NULL);
	}
	token = strtok(str_input, " \n\t\r\a");
	while (token)
	{
		tokens[index] = strdup(token);
		if (tokens[index] == NULL)
			exit(EXIT_FAILURE);
		index++;

		if (index >= bufferSize)
		{
			bufferSize *= 2;
			tokens = realloc(tokens, bufferSize * sizeof(char *));
			check_tokens(tokens);
		}
		token = strtok(NULL, " \n\t\r\a");
	}
	free(token);
	tokens[index] = NULL;
	return (tokens);
}
