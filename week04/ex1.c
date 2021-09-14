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
