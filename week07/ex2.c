#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the size of array (n): ");
  scanf("%d", &n);

  int* array = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    array[i] = i;
  }

  for (int i = 0; i < n; ++i) {
    printf("array[%d] = %d\n", i, array[i]);
  }

  free(array);
  
  return 0;
}
