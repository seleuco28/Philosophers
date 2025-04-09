
///////////////////////////////// DATA RACES ///////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 

int mails = 0;

void* routine()
{
    for (int i = 0; i < 1000000; i++) 
        mails++;
    /* 
    con numeros suficientemente altos ocurren data races
    lo que ocurre por detras en lenguaje maquina:
        1- read mails 
        2- increment the value
        3- write mails
    Si los threads hacen la operacion de leer a la vez y un hilo avanza y el otro no, se dan valores anomalos
    El sistema operativo hace que los hilos corran casi a la vez
     (si pongo numeros suficientemente altos el 1er hilo acaba antes de que empieze el 2ndo)
    */
}

int main(int ac, char **av)
{
    pthread_t t1 , t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0){
        return 2;
    }
    if (pthread_join(t1, NULL) != 0){
        return 3;
    }
    if (pthread_join(t2, NULL) != 0){
        return 4;
    }
    printf("Number of mails: %d\n", mails);
    return 0;
}