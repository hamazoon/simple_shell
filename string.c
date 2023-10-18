#include "shell.h"

/**
 * _str_length - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _str_length(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _str_compare - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: negative if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _str_compare(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _string_copy - Copies a string
 * @destination: The destination string
 * @source: The source string
 * Return: A pointer to the destination string
 */

char *_string_copy(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == NULL)
	return (destination);

	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}

	destination[i] = '\0';
	return (destination);
}

/**
 * _string_duplicate - Duplicates the given string
 * @str: The string to duplicate
 * Return: A pointer to the copied string (success),
 * NULL if failed or if str is NULL
 */
char *_string_duplicate(char *str)
{
	char *duplicate;
	unsigned int i = 0, length = 0;

	if (str == NULL)
	return (NULL);

	while (str[length])
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
	return (NULL);

	while ((duplicate[i] = str[i]) != '\0')
		i++;

	return (duplicate);
}

/**
 * _str_concatenate - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 * Return: a pointer to the resulting string
 */
char *_str_concatenate(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
		dest[i] = '\0';
	return (dest);
}
