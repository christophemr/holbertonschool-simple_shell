#ifndef SHELL_HEAD
#define SHELL_HEAD

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



char *get_user_input();
char **parse_input(char *str_input);
void runcmd(char **parsed_Input, char **env, char *shellpath);
char *get_path(char *parsed_input);
void free_tokens(char **tokens);
int check_builtin(char *input, char **env);

#endif

