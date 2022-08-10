#include "main.h"

/**
 * main - super simple shell that can run commands with their full path,
 * without any argument.
 * @argc: argument count
 * @argv: argument list
 *
 * Return: 0 on success.
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *lineptr = NULL;
	size_t n = 0;
	const char *delim = " ";
	char **words = NULL;
	pid_t pid;
	int status, loop = 1, count = 0, n_read = 0;

	while (loop)
	{
		/*Prompter*/
		write(1, "#cisfun$ ", 9);

		n_read = getline(&lineptr, &n, stdin);
		lineptr[n_read - 1] = '\0';

		words = tokenize(lineptr, delim, &count);

		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if (execve(words[0], &words[0], NULL) == -1)
			{
				perror("Error");
				free(lineptr);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(lineptr);
	return (0);
}

/**
 * tokenize - splits a string and returns an array of each
 * token/word of the string
 *
 * @text: string to tokenize
 * @delim: delimiter(s) - can handle multiple delimiters
 * @count: buffer to hold number of tokens returned by
 * function
 *
 * Return:  array of strings/tokens. Free allocated memory after use
 */

char **tokenize(char *text, const char *delim, int *count)
{
	char **words;
	int i, j, count_delim = 1;

	/*Estimate the number of tokens in view*/
	i = 0;
	while (text[i])
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (text[i] == delim[j])
				count_delim++;
		}
		i++;
	}
	/*Allocate memory based on tokens in view*/
	words = malloc(sizeof(char *) * count_delim);

	if (words == NULL)
	{
		printf("Malloc Failed!\n");
		exit(99);
	}
	/*Tokenize string and store in reserved array*/
	words[0] = strtok(text, delim);
	for (i = 1; i < count_delim; i++)
	{
		words[i] = strtok(NULL, delim);
	}

	i = 0;
	count_delim = 0;
	while (words[i] != NULL)
	{
		count_delim++;
		i++;
	}

	*count = count_delim - 1;
	return (words);
}
