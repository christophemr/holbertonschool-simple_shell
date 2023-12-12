#include "shell_header.h"
#include <stdio.h>
#include <unistd.h>


int pid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
