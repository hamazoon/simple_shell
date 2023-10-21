#include "shell.h"

/**
 * _execute - Executes a command with arguments.
 * @command: An array of strings representing the command and its arguments.
 * @arg: An array of strings representing the program's arguments.
 * @idx: the index of the array.
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **arg, int idx)
{
	pid_t child_pid;
	int status;
	char *full_cmd;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(arg[0], command[0], idx);
		free2D(command);
		return (127);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(full_cmd);
		free2D(command);
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			perror("execve");
			free(full_cmd);
			free2D(command);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(full_cmd);
		free2D(command);
		return (WEXITSTATUS(status));
	}

	return (-1);
}
