#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/shm.h>

/*---------------------------------------------------------------------*/
double calcula_pi(int initialize_at, double nr){
	double x, base, altura;
	double i, pi;

	base = 1.0 / nr;
        pi = 0.0;

       	for( i=initialize_at ; i<=nr ;  i += 3 ) {
                x = base * (( double)i - 0.5);
                altura = 4.0 / (1.0 + x*x);
		pi += base * altura;
	}

	return pi;


}
/*---------------------------------------------------------------------*/
int main(int argc, char **argv){

	double pi = 0;
	double numero_retangulos;
	double i;
  int id;
  int shared_memory_id;
  int chave = 0x5;
  double *vet = NULL;

	if ( argc != 2 ){
		printf("%s <num_retangulos>\n", argv[0]);
		exit(0);
	}


	numero_retangulos = atof(argv[1]);

  shared_memory_id = shmget(chave, 2 *sizeof(double), IPC_CREAT | 0600 );
  vet = shmat(shared_memory_id, 0, 0);

  id = fork();

  if ( id > 0 ) {

      id = fork ();
      if ( id > 0 ) {
        vet[0] = calcula_pi(2, numero_retangulos);
        wait(NULL);
        wait(NULL);
        pi = vet[0] + vet[1] + vet[2];
        printf("Pi = %.15f \n",pi);
        shmdt(vet);
        shmctl(shared_memory_id, IPC_RMID, NULL);
      } else {
        vet[2] = calcula_pi(2, numero_retangulos);
        shmdt(vet);
      }
  }
  else {
      vet[1] = calcula_pi(1, numero_retangulos);
      shmdt(vet);
  }

	// printf("Pi = %.15f\n",pi);
}
/*---------------------------------------------------------------------*/
