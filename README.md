# sistemasoperacionais

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int id;
    id = fork();
    if ( id > 0 ) {
     printf("Papis %d ID: %d \n", getpid(), id);
   	 sleep(2);
   	 kill(id, SIGSTOP);
   	 sleep(2);
   	 kill(id, SIGCONT);
   	 sleep(2);
   	 kill(id, SIGKILL);

    } else {
     printf("cria %d ID: %d \n", getpid(), id);
   	 while(1) {
   		 printf("*");
   	 }
    }
}

```
