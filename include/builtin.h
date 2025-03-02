#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdio.h>
#include <stdlib.h>

// Declare the global array (but do not define it here)
extern char *builtin_str[];

extern int (*builtin_func[])(char **);

int rksh_cd(char **args);
int rksh_help(char **args);
int rksh_exit(char **args);

// Function to get the number of built-in commands
int rksh_num_builtins();

#endif
