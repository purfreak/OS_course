#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void* my_realloc(void* ptr, size_t new_size, size_t origin_size) {
  void* newPtr = malloc(new_size);
  if (ptr == NULL) {
    return newPtr;
  }

  if (new_size == 0) {
    free(newPtr);
    free(ptr);
    return NULL;
  }

  memcpy(newPtr, ptr, new_size < origin_size ? new_size : origin_size);
  free(ptr);
  return newPtr;
}

int main() {
  int* a = (int*) malloc(sizeof(int) * 2);
  a[0] = a[1] = 5;
  printf("%d %d\n", a[0], a[1]);
  a = my_realloc(a, sizeof(int) * 4, sizeof(int) * 2);
  a[2] = a[3] = 100;
  printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
  a = my_realloc(a, sizeof(int), sizeof(int) * 4);
  printf("%d \n", a[0]);
  free(a);
  
  return 0;
}
