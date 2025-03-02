#ifndef PARSE_H
#define PARSE_H

#define RKSH_TOKEN_BUFFER_SIZE 64

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **rksh_parse_line(char *);

#endif