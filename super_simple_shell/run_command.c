#include "shell_header.h"

extern char **environ;

void runcmd(char **parsed_Input)
{
	char *command_path;
	pid_t child_pid;
	int status;

	/*recupere le path de la commande si il existe*/
	command_path = get_path(parsed_Input[0]);
	if(command_path == NULL)
	{
		printf("%s: command not found\n",parsed_Input[0]);
		return;
	}
	/* lance un child process ou faire l'execution*/
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
	}
	if (child_pid == 0)
	{
		/*si l'exec rate*/
		if(execve(command_path,parsed_Input, environ) == -1)
		{
			perror("Execution failed");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(&status);
		free(command_path);
	}
	return;
}
