#include "shell_header.h"

int main(void)
{
	char *usrInput;

	while (1)
	{
		printf("SS Shell ");
		usrInput = get_user_input();

		if (usrInput == NULL)
			break;
		printf("user input is: %s", usrInput);	
	}
	printf("\n");
	return (0);
}
