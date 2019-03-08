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

![image](https://user-images.githubusercontent.com/26127185/54059276-587ef480-41d7-11e9-8783-71759cff2470.png)

```c 
// Diretamente
#include <stdio.h>
#include <unistd.h>

int main() {
  int id;
  id = fork();
  if ( id > 0 ) {
    id = fork();
    if ( id > 0 ) { 
      id = fork();
    }
  }
}

// Indiretamente
#include <stdio.h>
#include <unistd.h>

int main() {
  int id;
  id = fork();
  if ( id == 0 ) {
    id = fork();
    if ( id == 0 ) {
      id = fork();
    }
  }
}
```
