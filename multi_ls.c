#include "shell_header.h"

int main(void)
{
	pid_t child_pid;
	int status, exec_status, i;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			exec_status = execve(argv[0], argv, NULL);
			if (exec_status == -1)
				return (-1);
		} else
		{
			waitpid(child_pid,&status, 0);
		}
	}
	return (0);
}
