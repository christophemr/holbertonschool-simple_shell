#include "shell_header.h"

char **split_string(char *str, char *delim, int *wordCount)
{
	char *token, *copy;
	int count = 0;
	char **words = malloc(100);

	copy = strdup(str);
	token = strtok(copy, delim);
	while (token)
	{
		words[count] = strdup(token);
		token = strtok(NULL, delim);
		count++;
	}
	*wordCount = count;
	return (words);
}

int main()
{
	char *inputString = "This is a sample string";
	char *delimiter = " ";
	int wordCount;
	char **words;
	
	words = split_string(inputString, delimiter, &wordCount);

	for (int i = 0; i < wordCount; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}

	free(words);

	return 0;
}