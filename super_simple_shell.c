#include "shell_header.h"

int main(void)
{
	char *usrInput;
	char **parsedInput;
	int i;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("Perfect Shell ");

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
			runcmd(parsedInput);


		free(usrInput);
	}
	return (0);
}
