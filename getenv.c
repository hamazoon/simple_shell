#include "shell.h"

/**
 * _getenv - Fetches the value of an environment variable.
 *
 * @variable: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value associated with 'variable' if found,
 *         or NULL if the variable is not found in the environment.
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _string_duplicate(environ[i]);
		key = strtok(tmp, "=");
		if (_str_compare(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _string_duplicate(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
