#include "main.h"

/**
  * print_envmnt - prints the environment string to stdout
  * Return: 0
  */

void print_envmnt(void)
{
	int x = 0;
	char **env = environment;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
	return (0);
}
