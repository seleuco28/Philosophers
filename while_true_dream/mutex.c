/*
    MUTEX:
        "MUtual EXclusion"
        "Sincronizar el uso de un recurso
        compartido entre hilos"
    ** Sin Mutex los hilos se interrumpen entre ellos, necesitamos
        semaforos para lockear y unlockear los recursos compartidos
*/



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int count = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *thread1_routine(void *unused)
{
    for (int i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
}

void *thread2_routine(void *unused)
{
    for (int i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mutex);
        count--;
        pthread_mutex_unlock(&mutex);
    }
}

void errorExit(char *strerr)
{
    perror(strerr);
    exit(1);
}

int main(int ac, char **av)
{
    pthread_t thread1, thread2;

    if (0 != pthread_create(&thread1, NULL, thread1_routine, NULL))
        errorExit("thread1 cannot be created");
    
    if (0 != pthread_create(&thread2, NULL, thread2_routine, NULL))
        errorExit("thread2 cannot be created");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("count value %d \n", count);
}