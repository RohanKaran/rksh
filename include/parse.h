#ifndef PARSE_H
#define PARSE_H

#define RKSH_TOKEN_BUFFER_SIZE 64
#define RKSH_TOKEN_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **rksh_parse_line(char *);

#endif