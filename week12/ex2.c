#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>

int main() {
  FILE *file;
  FILE *output_file;
  struct input_event event;
  char *line = (char*) malloc(50 * sizeof(char));

  output_file = fopen("./ex2.txt", "w+");
  file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");

  if (file != NULL) {
    while(1) {
      fread(&event, sizeof(struct input_event), 1, file);
      if (event.type == EV_KEY) {
        if (event.value == 0)
          sprintf(line, "\nRELEASED 0x%04x (%d)\n", event.code, event.code);
        else if (event.value == 1)
          sprintf(line, "\nPRESSED 0x%04x (%d)\n", event.code, event.code);
        else if (event.value == 2)
          sprintf(line, "\nHOLD 0x%04x (%d)\n", event.code, event.code);
        printf(line);
        fputs(line, output_file);
        fflush(output_file);
      }
    }

    fclose(file);
    fclose(output_file);
  }
}
