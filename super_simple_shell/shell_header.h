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
void runcmd(char **parsed_Input);
char *get_path(char *parsed_input);

#endif
