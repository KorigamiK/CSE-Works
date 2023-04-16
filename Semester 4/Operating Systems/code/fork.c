/** @brief Forks a new process and checks for parent and child processes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    printf("Child process pid: %d\n", (int)getpid());
    exit(EXIT_SUCCESS);
  } else if (pid > 0) {
    printf("Parent process pid: %d", (int)getpid());
  } else {
    printf("Fork failed");
    exit(EXIT_FAILURE);
  }
  return 0;
}
