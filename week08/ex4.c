#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct rusage usage;
  for (int i = 0; i < 10; i++) {
    void* allocated_memory = malloc(1000 * 1000 * 10);
    memset(allocated_memory, 0, 1000 * 1000 * 10);
    getrusage(RUSAGE_SELF, &usage);
    printf("ru_maxrss: %ld\n", usage.ru_maxrss);
    sleep(1);
  }
  
  return 0;
}
