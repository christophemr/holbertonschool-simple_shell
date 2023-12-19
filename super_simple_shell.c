#include "shell_header.h"
/**
 *main - entry point of the simple shell
 *@argc: Number of command-line arguments (unused)
 *@argv: Array of command-line arguments (unused)
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

	while (status)
	{
		status = isatty(0);

		if (status == 1)
			printf("$ ");

		/*recupere l'input*/
		usrInput = get_user_input();

		/*check si l'input n'a pas fonctionné pour quitter le shell*/
		if (usrInput == NULL)
			break;
		/*remplace le \n de l'input par \0 */
		usrInput[strcspn(usrInput, "\n")] = '\0';
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
				runcmd(parsedInput, env, argv[0]);
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
