#include "shell_header.h"
/*
 *main - main function for the simple shell
 *@argc: Number of command-line arguments (unused)
 *@argv: Array of command-line arguments (unused)
 *@env: Array of strings representing the environment variables
 *Return: 0 on success
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[],char **env)
{
	char *usrInput;
	char **parsedInput;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("$ ");

		/*recupere l'input*/
		usrInput = get_user_input();
			
		/*check si l'input n'a pas fonctionné pour quitter le shell*/
		if (usrInput == NULL)
			break;
		/*remplace le \n de l'input par \0 */
		usrInput[strcspn(usrInput, "\n")] = '\0';

		/*check si input est "exit" pour sortir*/
		if (strcmp(usrInput, "exit") == 0)
		{
			free(usrInput);
			break;
		}
		/*coupe la string en token*/
		parsedInput = parse_input(usrInput);
		
		if (parsedInput[0])
			runcmd(parsedInput, env);


		free(usrInput);
	}
	return (0);
}
