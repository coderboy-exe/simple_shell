#include <unistd.h>
#include <stdlib.h>
#define TOK_BUFSIZE 64

char **tokenize(char *lineptr)
{
	char *delimiter = " '\t''\n'";
	int bufsize =  TOK_BUFSIZE, position = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		perror("Allocation Error: \n");
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr, delimiter);
	while (token)
	{
		tokens[position] = strdup(token);

		token = strtok(NULL, delimiter);

		position++;
	}

	tokens[position] = token;

	return (tokens);
}
