#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of strings.
 * @line: The string to tokenize.
 *
 * Return: An array of strings (tokens) or NULL if allocation fails.
 */
char **tokenizer(char *line)
{
	int i;
	char *token = NULL;
	char **tokens = NULL;

	if (!line)
		return (NULL);

	token = strtok(line, DELIM);

	if (token == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * 1024);

	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}

	for (i = 0; token; i++)
	{
		tokens[i] = _string_duplicate(token);
		token = strtok(NULL, DELIM);
	}

	tokens[i] = NULL;
	free(line), line = NULL;
	return (tokens);
}
