#include "shell.h"

/**
 * execute_prompt - a function that execute a prompt
 * @prompt: The command entered in the prompt
 * Return: void
 */
void execute_prompt(const char *prompt)
{
	pid_t daugther_pid = fork();

	if (daugther_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (daugther_pid == 0)
	{
		char *token;
		char **args;
		int count = 0;
		int a = 0;
		char *prompt_copy = strdup(prompt);

		if (prompt_copy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(prompt_copy, " ");
		while (token != NULL)
		{
			count++;
			token = strtok(NULL, " ");
		}
		args = malloc((count + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		token = strtok(strdup(prompt), " ");
		count = 0;
		while (token != NULL)
		{
			args[count++] =strdup(token);
			token = strtok(NULL, " ");
		}
		args[count] = NULL;

		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		for (a = 0; a < count; a++)
		{
			free(args[a]);
		}

		free(prompt_copy);
		free(args);
	}
	else
	{
		wait(NULL);
	}

}

#include "shell.h"

/**
 * token_string - A function that tokenize a string arguments
 * @string: The string to be tokenized
 * Return: the void
 */

void token_string(const char *string)
{
	pid_t daugther_pid = fork();

	if (daugther_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (daugther_pid == 0)
	{
		char *argm[120];
		int count = 0;
		char *arg = strtok((char *)string, " ");

		while (arg != NULL)
		{
			argm[count++] = arg;
			arg = strtok(NULL, " ");
		}
		argm[count] = NULL;

		if (execvp(argm[0], argm) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

#include "shell.h"
/**
 * handle_path - a function that handle path
 * @path: the input command
 * Return: void
 */

void handle_path(const char *path)
{
	char *path_name = getenv("PATH");
	char *pathname_copy = strdup(path_name);
	char *delim = strtok(pathname_copy, " ");


	if (path_name == NULL)
	{
		printout("PATH environment variable not set.\n");

		return;
	}

	if (pathname_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	while (delim != NULL)
	{
		char execute[PATH_LENGTH];
		snprintf(execute, PATH_LENGTH, "%s/%s", delim, path);

		if (access(execute, X_OK) == 0)
		{
			printf("executing: %s\n", execute);
			execl(execute, path, NULL);
			perror("execl");
			exit(EXIT_FAILURE);
		}
		delim = strtok(NULL, " ");
	}

	printf("Command not found: %s\n", path);
	free(pathname_copy);
}
