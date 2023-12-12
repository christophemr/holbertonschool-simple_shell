#include "shell_header.h"

int main(void)
{
	char *path = getenv("PATH");
	char *token;

	token = strtok(path, ":");

	while (token)
	{
		printf("%s\n",token);
		token = strtok(NULL, ":");
	}
	return 0;

}
