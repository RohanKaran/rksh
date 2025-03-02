#include "execute.h"

#include "builtin.h"

int rksh_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            if (errno == ENOENT) {
                fprintf(stderr, "rksh: command not found: \"%s\"\n", args[0]);
            } else {
                perror("rksh");
            }
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        // Error forking
        perror("rksh: fork failed\n");
    }

    return 1;
}

int rksh_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    for (i = 0; i < rksh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return rksh_launch(args);
}