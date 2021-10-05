#include <stdio.h>
#include <stdlib.h>

int main() {
  // fixed
  char** s = (char**) malloc(sizeof(char*));
  char foo[] = "Hello World";
  *s = foo;
  // fixed
  printf("s is %p\n", s);
  s[0] = foo;
  printf("s [0] is %s\n", s[0]);
  free(s);
  return (0);
}
