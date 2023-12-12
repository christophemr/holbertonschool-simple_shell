#include "shell_header.h"

int main(int argc, char *argv[], char **env)
{
	char *string;

	string = prompt();
	printf("the string is %s\n", string);
	return (0);
}
