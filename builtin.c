#include "shell_header.h"

int check_builtin(char *input, char **env)
{
	int i = 0;

	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(input, "env") == 0)
	{

		for (i = 0; env[i] != NULL; i++)
		{
			printf("%s\n", env[i]);
		}
		return (1);
	}
	return (0);
}
