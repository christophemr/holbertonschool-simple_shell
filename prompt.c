#include "shell_header.h"

char *prompt(void)
{
	char *buffer, *exit = "exit\n";
	size_t n = 10;
	ssize_t line;
	
	while (1)
	{
		printf("(╭ರ_•́) ");
		line = getline(&buffer, &n, stdin);
		if (line == -1)
		{
			perror("Closing the shell");
			break;
		}
		if(strcmp(buffer,exit) == 0)
		{
			break;
		}
		printf("%s", buffer);
	}
	return (buffer);
}
