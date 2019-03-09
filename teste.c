#include <stdio.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0){
    pid = fork();
    if (pid == 0) {
      pid = fork();
    }
  }
  sleep(61);
}
