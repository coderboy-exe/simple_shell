#include <unistd.h>
#include <stdlib.h>

/**
 *
 */

char *read_line(void)
{
	char *lineptr = NULL;
	ssize_t bufsize = 0; //allocate a buffer with getline()
	ssize_t line;

	line = getline(&lineptr, &bufsize, stdin);

	if (line == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS); //Recieved an EOF
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return (lineptr);
}
