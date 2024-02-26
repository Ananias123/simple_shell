#include "shell.h"

/**
 * main - Entry point
 *
 * Return: the integer
 */
int main(void)
{
	char str[124];

	while (true)
	{
		prompt_display();
		user_input(str, sizeof(str));
		token_string(str);
		execute_prompt(str);
		handle_path(str);

	}
	return (0);
}
