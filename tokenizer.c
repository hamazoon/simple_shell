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
	int token_count = 0;
	char *token = NULL;
	char **tokens = NULL;

	if (!line)
		return (NULL);

	token = strtok(line, DELIM);

	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}
	free(token);

	tokens = malloc(sizeof(char *) * (token_count + 1));

	if (!tokens)
		return (NULL);
	token = strtok(line, DELIM);
	for (i = 0; i < token_count; i++)
	{
		tokens[i] = _string_duplicate(token);
		token = strtok(NULL, DELIM);
	}

	tokens[token_count] = NULL;
	return (tokens);
}
