#include "envread.h"
#include <ctype.h>
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
  if (!f)
    return NULL;
  // allocating to buffer
  size_t size = sizeof(char) * BUFFSZ;
  char *buff = malloc(size);
  // reading file and storing in buffer
  fgets(buff, size, f);

  int key_size = strlen(var) + 1;
  char *line = malloc(key_size);
  strcat(line, var);
  line[key_size - 1] = '=';
  printf("linha montada: %s\n", line);

  char *pos = strstr(buff, line);
  if (pos != NULL) {
    ptrdiff_t index = pos - buff;
    char *value = malloc(size);
    char *p = &buff[index + strlen(line)];
    for (int i = 0; isalnum(*p); i++, p++) {
      value[i] = *p;
    }
    return value;
  }

  return NULL;
}

void envread_close(FILE *f) { fclose(f); }
