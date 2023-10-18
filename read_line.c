#include "shell.h"

/**
 * read_line - Reads a line of text from standard input (stdin).
 *
 * Return: A pointer to the string containing the input line.
 *         If an error occurs or if the end of input is reached, returns NULL.
 */

char *read_line(void)
{
	char *chaine = NULL;
	size_t lenght = 0;

	if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&chaine, &lenght, stdin) == -1)
	{
		free(chaine);
		return (NULL);
	}

	return (chaine);
}
