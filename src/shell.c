#include "shell.h"

#include "execute.h"
#include "parse.h"
#include "read.h"

void handle_sigint(int sig) {
    (void)sig;  // Suppress unused parameter warning
    write(STDOUT_FILENO, "\nrksh> ", 8);
}

void start_rksh_shell(void) {
    char *line;
    char **args;
    int status;

    signal(SIGINT, handle_sigint);

    do {
        printf("rksh> ");

        line = rksh_read_lines();
        args = rksh_parse_line(line);
        status = rksh_execute(args);

        free(line);
        free(args);
    } while (status);
}