//Universidad del Valle de Guatemala
//Sistemas Operativos
//Programa de Semaforos en C
//Juan Guillermo Sandoval 

//Paquetes
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unist.h>

//De la libreria semaphore.h
sem_t semaforo;

void * createdThread(void * arg)
{
    printf("\n Thead %d creado \n", pthread_self() * -1);

    int j;
    for (j=0; j<7; j++){
        printf("Inicio del thread: %d \n", j + 1);
        sem_wait(&semaforo);
        printf("Entro por el recurso \n");
        printf("Recurso usado \n");
        printf("Terminando de usar el semaforo \n");
        sem_post(&semaforo);
    }
}

int main()
{
    int cont = 7;
    printf("\n Iteracion: %d \n", cont);
    printf("Iniciando programa: \n");
    sem_init(&semaforo, 0, 1);
    printf("Creando threads \n")

    pthread_t threads[7];

    int i;
    for (i=0; i<8; i++){
        pthread_create(&threads[i], NULL, createdThread, NULL);
        pthread_join(threads[i], NULL);
    }

    printf("fin del programa");
    sem_destroy(&semaforo);
    return 0;
    
}