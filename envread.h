#ifndef ENVREAD_H
#define ENVREAD_H

#include <stdio.h>
FILE *envread_init(const char *path);
char *envread(FILE *f, const char *var);
void envread_close(FILE *f);

#endif
