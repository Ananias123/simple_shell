#include "shell.h"

/**
 * printout - A function that prints to the stdout
 * @string: the string to be printed out
 * Return: Nothing
 */
void printout(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
