#include "shell.h"

/**
 * main - Entry point of a simple shell program.
 * @ac: The number of command-line arguments (unused).
 * @argv: An array of command-line argument strings (unused).
 *
 * Return: The exit status of the shell program.
 */

int main(int ac, char **argv)
{
	char *chaine = NULL;
	char **command = NULL;
	int idx = 0;
	int exit_status = 0;

	(void) ac;
	while (1)
	{
		chaine = read_line();
		if (chaine == NULL)
		{
			if (isatty(STDOUT_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (exit_status);
		}
		idx++;
		command = tokenizer(chaine);
		if (!command)
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command, argv, &exit_status, idx);
		else
			exit_status = _execute(command, argv, idx);
	}
}
