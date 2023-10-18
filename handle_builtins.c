#include "shell.h"

/**
 * is_builtin - vérifie si une commande est intégrée.
 *
 * @command: La chaîne de caractères représentant la commande à vérifier.
 * Return: 1 si la commande est intégrée, 0 sinon
 */

int is_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(command, builtins[i]) == 0)
		return (1);
	}
	return (0);
}
/**
 * handle_builtin - handling the execution of built-in commands.
 *
 * @command: The command to be handled.
 * @argv: The array of command arguments.
 * @status: A pointer to the execution status.
 * @idex: An index or identifier.
 */

void handle_builtin(char **command, char **argv, int *status, int idex)
{
	if (strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idex);
	else if (strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - Handle the 'exit' command in the shell.
 *
 * This function is responsible for processing the 'exit' command in the shell.
 * It allows the user to exit the shell with an optional status code.
 *
 * @command: The command being handled.
 * @argv: The array of command arguments.
 * @status: A pointer to the execution status, which may be modified.
 * @idex: An index or identifier (not used in this function).
 */

void exit_shell(char **command, char **argv, int *status, int idex)
{
	int exit_value = (*status);
	char *index;

	char mssg[] = ": exit: illegal number: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(exit_value);
			write(STDERR_FILENO, argv[0], _str_length(argv[0]));
			write(STDERR_FILENO, "; ", 2);
			write(STDERR_FILENO, index, _str_length(index));
			write(STDERR_FILENO, mssg, _str_length(mssg));
			write(STDERR_FILENO, command[1], _str_length(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2D(command);
			return;
		}
	}
	free2D(command);
	exit(exit_value);
	(void)idex;
}
/**
 * print_env - printing environment variables to the standar output.
 *
 * @command: The command, which may not be used in this function.
 * @status: A pointer to the execution status.
 */

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[0]; i++)
	{
		write(STDOUT_FILENO, environ[i], _str_length(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2D(command);
	(*status) = 0;
}
