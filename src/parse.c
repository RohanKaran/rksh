#include "parse.h"

char **rksh_parse_line(char *line) {
    int buffer_size;
    int position;
    char **tokens;
    int i;
    char *token;
    int token_pos;

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

        token = malloc(strlen(&line[i]) + 1);  // Max possible size
        if (!token) {
            fprintf(stderr, "rksh: allocation error\n");
            exit(EXIT_FAILURE);
        }
        token_pos = 0;

        if (line[i] == '"') {
            i++;  // Skip opening double quote
            while (line[i] != '\0') {
                if (line[i] == '\\') {
                    i++;
                    if (line[i] == '"' || line[i] == '\\') {
                        token[token_pos++] = line[i++];
                    } else if (line[i] != '\0') {
                        token[token_pos++] = '\\';
                        token[token_pos++] = line[i++];
                    }
                } else if (line[i] == '"') {
                    i++;  // Closing double quote
                    break;
                } else {
                    token[token_pos++] = line[i++];
                }
            }
        } else {
            while (line[i] != '\0' && !isspace(line[i])) {
                token[token_pos++] = line[i++];
            }
        }

        token[token_pos] = '\0';
        tokens[position++] = token;

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
