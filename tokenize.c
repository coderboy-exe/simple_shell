#include "main.h"


/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: string buffer to tokenize
 * @delimiter: delimiter to be used for tokenization
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Error (Fatal)");
		return (NULL);
	}
	while ((tokens[i] = _strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Error (Fatal)");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
