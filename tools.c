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

	free(arr);
}
