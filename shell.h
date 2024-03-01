#ifndef SHELL_H
#define SHELL_H
#define PATH_LENGTH 1024
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


void printout(const char *string);
void prompt_display(void);
void execute_prompt(const char *prompt);
void user_input(char *string, size_t n_bytes);
void token_string(const char *string);
void handle_path(const char *path);



#endif
