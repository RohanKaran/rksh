#include "builtin.h"

/*
  Function Declarations for builtin shell commands:
 */
int rksh_cd(char **args);
int rksh_help(char **args);
int rksh_exit(char **args);
/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {"cd", "help", "exit"};

int (*builtin_func[])(char **) = {&rksh_cd, &rksh_help, &rksh_exit};

int rksh_num_builtins() { return sizeof(builtin_str) / sizeof(char *); }

/*
  Builtin function implementations.
*/
int rksh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "rksh: expected argument to \"cd\".\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("rksh");
        }
    }
    return 1;
}

int rksh_help(char **args) {
    if (args[1] != NULL) {
        printf("Use \"man %s\" for information.\n\n", args[1]);
    }
    int i;
    printf(":) Rohan Karan's RKSH: https://github.com/RohanKaran/rksh\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");
    for (i = 0; i < rksh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int rksh_exit(char **args) {
    if (args[1] != NULL) {
        fprintf(stderr, "rksh: \"exit\" does not accept any arguments.\n");
        return 1;
    }
    return 0;
}