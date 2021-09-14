/*
The output is different, because when new processes are created, they take free PID by order
(if PID will be maximum, PID will be cleared and equal to 2)
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid;
  switch (pid = fork()) {
    case 0: printf("Hello from child [PID - %d]\n", getpid());
      break;

    default: waitpid(pid, NULL, 0);
      printf("Hello from parent [PID - %d]\n", getpid());
      break;
  }
  printf("\n");

  return 0;
}
