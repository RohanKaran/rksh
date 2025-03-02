#include "parse.h"

char **rksh_parse_line(char *line) {
    int buffer_size = RKSH_TOKEN_BUFFER_SIZE, position = 0;
    char **tokens = malloc(sizeof(char *) * buffer_size);
    char *token;

    if (!tokens) {
        fprintf(stderr, "rksh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, RKSH_TOKEN_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += RKSH_TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "rksh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, RKSH_TOKEN_DELIM);
        // printf("%s\n", token);
    }
    tokens[position] = NULL;
    return tokens;
}