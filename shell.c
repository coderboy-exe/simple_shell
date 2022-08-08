#include <unistd.h>
#include <stdio.h>

/**
 * 
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	ssize_t read_line;
	char *lineptr = NULL;
	size_t n = 0;
	char *delimiter = " :'\n''\t'";


	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);

		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "~$ ", 13);
		}

	}
}
