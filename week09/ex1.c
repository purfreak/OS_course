#include <stdio.h>
#include <stdlib.h>

FILE* input_file;
long long frames_count;
long long hit = 0, miss = 0;

struct frame* frames;

struct frame {
  int age;
  int page_num;
};

void updateFrames(int next_page) {
  long min_index = 0;
  for (long i = 0; i < frames_count; ++i) {
    if (frames[i].page_num == -1) {
      min_index = i;
      break;
    }
    if (frames[i].age < frames[min_index].age) {
      min_index = i;
    }
    frames[i].age >>= 1;
  }

  for (long i = 0; i < frames_count; ++i) {
    if (frames[i].page_num == next_page) {

      frames[i].age |= (1 << 7);
      ++hit;
      return;
    }
  }

  ++miss;
  frames[min_index].age = 1 << 7;
  frames[min_index].page_num = next_page;
}

int main() {
  printf("Enter number of frames: ");
  scanf("%ld", &frames_count);
  printf("\n");

  frames = malloc(frames_count * sizeof(struct frame));
  if (frames == NULL) {
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < frames_count; ++i) {
    frames[i].age = 0;
    frames[i].page_num = -1;
  }

  input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    free(frames);
    exit(EXIT_FAILURE);
  }

  int next_page;
  while (fscanf(input_file, "%d", &next_page) != EOF) {
    updateFrames(next_page);
  }

  printf("Hits number: %lld\n", hit);
  printf("Misses number: %lld\n", miss);
  printf("Hits/Misses ratio: %f\n", (double) hit / miss);

  free(frames);
}
