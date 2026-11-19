#include "envread.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSZ 4096

FILE *envread_init(const char *path) {
  if (!path)
    return NULL;
  FILE *f = fopen(path, "r");
  return f;
}

char *envread(FILE *f, const char *var) {
  // allocating to buffer
  size_t size = sizeof(char) * BUFFSZ;
  char *buff = malloc(size);
  // reading file and storing in buffer
  fgets(buff, size, f);

  char *line = malloc(strlen(var) + 1);
  strcat(line, var);
  line[strlen(var)] = '=';

  // check if line exists on file
  char *pos = strstr(buff, line);

  if (pos != NULL) {

    int index = (int)(pos - buff);
    char *value = malloc(size);
    char *p = &buff[index + strlen(line)];

    for (int i = 0; *p != '\n'; i++, p++) {
      if (*p == '"') {
        i--;
        continue;
      }
      if (*p == '\'') {
        i--;
        continue;
      }
      value[i] = *p;
    }
    free(buff);

    return value;
  }

  return NULL;
}

void envread_close(FILE *f) { fclose(f); }
