#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>

int main() {
  FILE* file;
  FILE* output_file;
  
  struct input_event event;
  int state = 0;
  short P_PRESSED = 0, E_PRESSED = 0, A_PRESSED = 0, C_PRESSED = 0, PLUS_PRESSED = 0;

  output_file = fopen("./ex3.txt", "w+");
  file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
  
  if (file != NULL) {
    printf("Try to press the following shortcuts:\nP + E, C + A + P, C + '+'(Plus button)\n");
    fprintf(output_file, "Try to press the following shortcuts:\nP + E, C + A + P, C + '+'(Plus button)\n");
    fflush(output_file);
    
    while (1) {
      fread(&event, sizeof(struct input_event), 1, file);
      if (event.type == EV_KEY) {
        if (event.value == 0) {
          switch (event.code) {
            case KEY_A:
              A_PRESSED = 0;
              break;
            case KEY_C:
              C_PRESSED = 0;
              break;
            case KEY_E:
              E_PRESSED = 0;
              break;
            case KEY_P:
              P_PRESSED = 0;
              break;
            case KEY_KPPLUS:
              PLUS_PRESSED = 0;
              break;
          }
        } else if (event.value == 1) {
          switch (event.code) {
            case KEY_A:
              A_PRESSED = 1;
              break;
            case KEY_C:
              C_PRESSED = 1;
              break;
            case KEY_E:
              E_PRESSED = 1;
              break;
            case KEY_P:
              P_PRESSED = 1;
              break;
            case KEY_KPPLUS:
              PLUS_PRESSED = 1;
              break;
          }
        }
        
        if (P_PRESSED && E_PRESSED) {
          printf("I passed the Exam!\n");
          fputs("I passed the Exam!\n", output_file);
        }
        if (A_PRESSED && C_PRESSED && P_PRESSED) {
          printf("Get some cappuccino!\n");
          fputs("Get some cappuccino!\n", output_file);
        }
        if (C_PRESSED && PLUS_PRESSED) {
          printf("I like C++!\n");
          fputs("I like C++!\n", output_file);
        }
        fflush(output_file);
      }
    }
    fclose(file);
    fclose(output_file);
  }
}
