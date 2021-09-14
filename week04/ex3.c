#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char str[256];
  scanf("%s", str);

  int pid;
  pid = fork();
  if (pid == 0) {
    char *args[] = {str, NULL};
    execvp(str, args);
    return 0;
  }

  waitpid(pid, NULL, 0);
  return 0;
}
