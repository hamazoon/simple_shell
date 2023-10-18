#include "shell.h"

/**
 * _execute - Executes a command with arguments.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the program's arguments.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{

		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2D(command);
	}

	return (WEXITSTATUS(status));
}
