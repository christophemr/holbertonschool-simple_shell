#include "shell_header.h"
/**
 * main - function in wich argumenents line are 
 * passed trough
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int arguments(int ac, char **av)
{
	int i;

	printf("argc = %d\n", ac);
	printf("command line argument are: \n");

	for (i = 0; i < ac; i++)
	{
		printf("argv[%d] = %s\n", i, av[i]);
	}
	return (0);
}

