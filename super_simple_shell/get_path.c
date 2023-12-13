#include "shell_header.h"

char *get_path(char *parsed_input)
{
	char *path = getenv("PATH");
	char *dup_path = NULL, *dir_name = NULL, *fullpath = NULL;
	struct stat filestate;

	if (path == NULL)
	{
		perror("PATH environment not found.\n");
		return (NULL);
	}
	dup_path = strdup(path);
	if (dup_path == NULL)
	{
		perror("Duplication of path failed\n");
		return (NULL);
	}
	/* coupe les dossier du path au char ':'*/
	dir_name = strtok(dup_path, ":");
	while (dir_name)
	{
		/*malloc le fullpath de la taille du dossier + char "/" + input + "\0"*/
		fullpath = malloc(strlen(dir_name) + strlen(parsed_input) + 2);
		if (fullpath == NULL)
		{
			perror("Memory allocation of fullpath failed");
			free(dup_path);
			return (NULL);
		}
		/*ecrit "dir_name/parsed_input" dans le fullpath */
		sprintf(fullpath, "%s/%s", dir_name, parsed_input);
		/* si fullpath mene a un dossier, sort de la boucle */
		if (stat(fullpath, &filestate) == 0)
		{
			break;
		}
		free(fullpath);
		/*reset fullpath a null pour retourner null si pas de path correspondant*/
		fullpath = NULL;
		dir_name = strtok( NULL, ":");
	}
	free(dup_path);
	return (fullpath);

}
