#include "shell_header.h"
/**
 * runcmd - Executes a command with optional path resolution
 * @parsed_Input: Parsed command and arguments
 * @env: Array of strings representing the environment variables
 */


void runcmd(char **parsed_Input, char **env, char *shellpath, char *userinput)
{
	char *command_path;
	pid_t child_pid;
	int status, cmd_status;

	if (parsed_Input[0][0] == '/' || parsed_Input[0][0] == '.')
		command_path = strdup(parsed_Input[0]);
	else
		command_path = get_path(parsed_Input[0]);
	if (command_path == NULL || access(command_path, X_OK) != 0)
	{
		if(isatty(fileno(stdin)))
			fprintf(stderr, "%s: %s: No such file or directory\n", shellpath, parsed_Input[0]);
		else
		{
			free(userinput);
			fprintf(stderr, "%s: 1: %s: not found\n", shellpath, parsed_Input[0]);
			free_tokens(parsed_Input);
			exit(127);
		}
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		free(command_path);
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(command_path, parsed_Input, env) == -1)
		{
			perror("Execution failed");
			free(userinput);
			free_tokens(parsed_Input);
			free(command_path);
			exit(127);
		}
	} else
	{
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status))
		{
			cmd_status = WEXITSTATUS(status);
			free(command_path);
			if (cmd_status != 0)
			{
				free(userinput);
				free_tokens(parsed_Input);
				exit(cmd_status);
				
			}
		}
		else
		{
			free(command_path);
		}
	}
}
