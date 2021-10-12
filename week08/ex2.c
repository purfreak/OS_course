/*
The amount of free memory decreases as the code allocates it, amount of used memory increases
the code takes more and more memory over time, and it becomes higher in `top -d1` command (the values of RES and %MEM increase)
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  for (int i = 0; i < 10; i++) {
    void* allocated_memory = malloc(1000 * 1000 * 10);
    memset(allocated_memory, 0, 1000 * 1000 * 10);
    sleep(1);
  }
  
  return 0;
}
