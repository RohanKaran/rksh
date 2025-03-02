#include "parse.h"

char **rksh_parse_line(char *line) {
    int buffer_size;
    int position;
    char **tokens;
    int i;
    char *start;
    int length;
    char *token;

    buffer_size = RKSH_TOKEN_BUFFER_SIZE;
    position = 0;
    i = 0;

    tokens = malloc(sizeof(char *) * buffer_size);
    if (!tokens) {
        fprintf(stderr, "rksh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (line[i] != '\0') {
        while (isspace(line[i])) i++;  // Skip whitespace

        if (line[i] == '\0') break;

        if (line[i] == '"') {
            // Quoted token
            i++;  // Skip opening quote
            start = &line[i];
            while (line[i] != '\0' && line[i] != '"') i++;
        } else {
            // Normal token
            start = &line[i];
            while (line[i] != '\0' && !isspace(line[i])) i++;
        }

        length = &line[i] - start;
        token = malloc(length + 1);
        strncpy(token, start, length);
        token[length] = '\0';

        tokens[position++] = token;

        if (line[i] == '"') i++;  // Skip closing quote

        if (position >= buffer_size) {
            buffer_size += RKSH_TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "rksh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    tokens[position] = NULL;
    return tokens;
}
