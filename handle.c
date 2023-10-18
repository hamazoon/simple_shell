#include "shell.h"

/**
 * _getpath - Find a command by searching PATH or an absolute path.
 * @command: Command to locate.
 *
 * Return: Full path to the command if found, or NULL if not found or on error.
 */

char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (_string_duplicate(command));
			}
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_str_length(dir) + _str_length(command) + 2);
		if (full_cmd)
		{
			_string_copy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd =  NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
