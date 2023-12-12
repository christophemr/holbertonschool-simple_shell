#include "shell_header.h"

int main(void)
{
	char *buffer;
	size_t n = 10;
	ssize_t line;

	printf("$ ");
	line = getline(&buffer, &n, stdin);
	if (line == -1)
	{
		perror("can't read the command");
	}
	printf("%s", buffer);
	return (line);
}
