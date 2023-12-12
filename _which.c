#include "shell_header.h"
#include <sys/stat.h>

int _which(int argc, char *argv[])
{
	const char *file_name = argv[1], *path = getenv("PATH");
	char *dup_path, *token, fullPath[256];
	struct stat st;

	if (argc != 2)
	{
		fprintf(stderr,"Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	if (path == NULL)
	{
		fprintf(stderr,"Error, environment not found.\n");
		return (1);
	}
	dup_path = strdup(path);
	if (dup_path == NULL)
	{
		perror("Error duplication");
		return (1);
	}
	token = strtok(dup_path, ":");
	while (token != NULL)
	{
		/*snprintf() formate et store une serie de char et valeur dans un buffer*/
		snprintf(fullPath, sizeof(fullPath), "%s/%s", token, file_name);
		if (stat(fullPath,&st) == 0)
		{
			printf("%s\n", fullPath);
			return (0);
		}
		token = strtok(NULL, ":");
	}
	printf("File not found\n");
	free(dup_path);
	return (0);
}
