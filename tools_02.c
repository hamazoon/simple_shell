#include "shell.h"
/**
 * is_positive_number - Check if a string represents a positive integer.
 *
 * it checks if the given string 'str' represents a valid positive integer.
 *
 * @str: The string to be checked for being a positive integer.
 *
 * Return: 1 if 'str' is a positive integer, 0 otherwise.
 */
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0 ; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
			}
		return (1);
	}
/**
 * _atoi - Convert a string to an integer.
 *
 * This function converts the given string 'str' into an integer.
 * the input string contains a valid integer representation.
 *
 * @str: The string to be converted to an integer.
 *
 * Return: The integer value obtained from 'str'.
 */
int _atoi(char *str)
{
	int i = 0;
	int num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
