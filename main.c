#include "envread.h"
#include <stdio.h>

int main() {
  char *env = "./.env";
  FILE *f = envread_init(env);
  if (!f) {
    printf("file doesnt exists!");
    return 1;
  }
  const char *test = envread(f, "TEST");
  printf("test: %s", test);
}
