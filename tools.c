#include "shell.h"

/**
 * free2D - Frees memory allocated for a 2D array of strings.
 * @arr: The 2D array of strings to be freed.
 */

void free2D(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}


/**
 * printerror - Print an error message with context information.
 *
 * This function is used to print an error message along with specific
 * context information such as 'name', 'cmd', and 'idx'.
 *
 * @name: The name associated with the error.
 * @cmd: The command or action causing the error.
 * @idx: An integer index or identifier relevant to the error.
 */

void printerror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _str_length(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _str_length(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _str_length(cmd));
	write(STDERR_FILENO, mssg, _str_length(mssg));
	free(index);
}
/**
 * _itoa - Convert an integer to a string.
 *
 * Dynamically allocates a character buffer to store the result string
 * representation of the integer 'n'. The return value is a newly
 * allocated string containing the integer's string representation.
 *
 * @n: The integer to convert to a string.
 *
 * Return: A dynamically allocated string containing the integer's string
 * representation, or NULL on allocation failure.
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_string_duplicate(buffer));
}

/**
 * reverse_string - Reverse the characters in a string.
 * @str: The input string to be reversed.
 * @len: Length of the input string.
 *
 * Reverses the characters in the given string in-place.
 * Returns: None.
 */

void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}


