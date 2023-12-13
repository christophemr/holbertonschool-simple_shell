#include "shell_header.h"

int main(void)
{
	char *usrInput;

	while (1)
	{
		printf("SS Shell ");

		/*recupere l'input*/
		usrInput = get_user_input();
		
		/*check si l'input n'a pas fonctionné pour quitter le shell*/
		if (usrInput == NULL)
			break;
		/*remplace le \n de l'input par \0 */
		usrInput[strcspn(usrInput,"\n")] = '\0';

		/*check si input est "exit" pour sortir*/
		if(strcmp(usrInput, "exit") == 0)
		{
			free(usrInput);
			break;
		}
		printf("user input is: %s\n", usrInput);
		free(usrInput);
	}
	return (0);
}
