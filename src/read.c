#include "read.h"

char *rksh_read_lines(void) {
    int buffer_size = RKSH_RL_BUFFER_SIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    int c;

    if (!buffer) {
        fprintf(stderr, "rksh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF && position == 0) {
            fprintf(stdout, "rksh: logout\n");
            free(buffer);
            exit(EXIT_SUCCESS);
        } else if (c == EOF) {
            clearerr(stdin);
            continue;
        } else if (c == 127 || c == 8) {
            // Handle backspace (127 = DEL, 8 = BS)
            if (position > 0) {
                position--;
                printf("\b \b");
                fflush(stdout);
            }
            continue;
        } else if (c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate.
        if (position >= buffer_size) {
            buffer_size += RKSH_RL_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                fprintf(stderr, "rksh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}