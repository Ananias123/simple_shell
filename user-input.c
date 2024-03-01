#include "shell.h"

/**
 * user_input - A function that receive user input
 * @string: the input of the user
 * @n_bytes: The number of bytes a string will occupy
 * Return: void
 */
void user_input(char *string, size_t n_bytes)
{
	if (fgets(string, n_bytes, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printout("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printout("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	string[strcspn(string, "\n")] = '\0';

}
