#include "envread.h"
#include <stdio.h>

int main() {
  char *env = "./.env";
  FILE *f = envread_init(env);
  if (!f) {
    printf("file doesnt exists!");
    return 1;
  }
  char *test = envread(f, "TEST");
  char *url = envread(f, "DATABASE_URL");
  printf("database url: %s\n", url);
  printf("test: %s", test);
}
