# Fundamentos de Sistemas Operacionais

## Processo 
- Segmento de código compilado [CS]
- Segmento de dados [DS]
- Base da Pilha e Segmento da Pilha [BP + SP] (limitado 8k)
- Heap (Alocação dinâmica)
- Program Count [PC] 
    
## Comandos úteis

-  `top` - Displays active processes. Press q to quit
- `size file` - Displize file size
- `ps` - Processos rodando
- `ps -u lucaskuhn | wc -l` - Número de processos rodando
- `ps -aH` - Lista arvores de processos
- `pstree` - Lista arvore de processos para mac
- `kill pid` - Mata o processo a partir do seu pid ( pode ser chegado com `ps`)
- `kill -l` - Lista sinais que o kill recebe
- `killall -9 nomedoprocesso` - Mata o processo
- `ipcs` - Inter process communication
- `ipcrm -M 5` - Remove memory 5

    
Faça um programa que crie um programa filho (utilizado por outro core do CPU), deixe ele rodar por 2 segundos, pausar por 2 segundos, rodar mais 2 segundos, e por fim terminar o processo:
```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int id;
    id = fork();
    if ( id > 0 ) {
     printf("PAI %d ID: %d \n", getpid(), id);
   	 sleep(2);
   	 kill(id, SIGSTOP);
   	 sleep(2);
   	 kill(id, SIGCONT);
   	 sleep(2);
   	 kill(id, SIGKILL);

    } else {
     printf("FILHO %d ID: %d \n", getpid(), id);
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
