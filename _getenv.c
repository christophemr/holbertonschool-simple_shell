#include "shell_header.h"

extern char **environ;

int main(void)
{
	const char *path = getenv("PATH");
	char *pathname = "PATH";
	int i = 0;

	printf("%s\n", path);
	if (path == NULL || pathname == NULL || strlen(pathname) == 0)
	{
		fprintf(stderr, "Error: Invalid environment name \n");
		return 1;
	}
	while(environ[i])
	{
		if (strncmp(environ[i] , pathname, strlen(pathname)) == 0)
		{
			printf("%s\n", environ[i] + strlen(pathname) + 1);
		}
		i++;
	}

	return (0);
}
