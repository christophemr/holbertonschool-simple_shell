#include "shell_header.h"
/**
 *main - entry point of the simple shell
 *@argc: Number of command-line arguments (unused)
 *@argv: Array of command-line arguments
 *@env: Array of strings representing the environment variables
 *Return: 0 on success
 */

int main(__attribute__((unused)) int argc,
		 char *argv[],
		 char **env)
{
	char *usrInput;
	char **parsedInput;
	int status = 1, isbuiltin = 0;

	while (1)
	{
		status = isatty(0);

		if (status == 1)
			printf("$ ");

		usrInput = get_user_input();

		if (usrInput == NULL)
			break;
		isbuiltin = check_builtin(usrInput, env);
		if (isbuiltin == 0)
		{
			parsedInput = parse_input(usrInput);
			if (parsedInput == NULL)
			{
				free(usrInput);
				continue;
			}
			if (parsedInput[0])
				runcmd(parsedInput, env, argv[0], usrInput);
			free_tokens(parsedInput);
		}
		free(usrInput);
	}
	return (0);
}

/**
 * free_tokens - free allocated memory
 * @tokens: array to free
 */

void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
