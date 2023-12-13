#include "shell_header.h"

void check_tokens(char **tokens)
{
	if (tokens == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
}

char **parse_input(char *str_input)
{
	int bufferSize = 128, index = 0;
	char *token;
	char **tokens = malloc(bufferSize * sizeof(char *));
	
	check_tokens(tokens);
	/*découpe le string au whitespace et retour a la ligne*/
	token = strtok(str_input, " \n");
	/*tant qu\'il y a un token,l'ajoute a tokens[index] */
	while (token)
	{
		tokens[index] = strdup(token);
		index++;
		
		/*si l'espace alloué a tokens n'est pas assez élevé, realloue de la mémoire*/
		if (index >= bufferSize)
		{
			bufferSize *= 2;
			tokens = realloc(tokens, bufferSize *sizeof(char *));
			check_tokens(tokens);	
		}
		token = strtok(NULL, " \n");
	}
	tokens[index] = NULL;
	return (tokens);
}


