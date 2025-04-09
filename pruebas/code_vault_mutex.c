
///////////////////////////////////// MUTEX //////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 

int mails = 0;
pthread_mutex_t mutex; //declaro variable pero no inicializo


void* routine()
{
    
    for (int i = 0; i < 1000000; i++) 
    {
        //esta función hace que mutex lockee
        pthread_mutex_lock(&mutex);
        mails++;
        //esta otra hace que mutex unlockee
        pthread_mutex_unlock(&mutex);
        //una vez puesto los locks y unlocks ya no tendria que tener data races 
        //mutex lo que hace es protejer el codigo de otros hilos que se puedan ejecutar a la vez
    }
}

int main(int ac, char **av)
{
    pthread_t t1 , t2;
    //inicializo el mutex aqui
    // 1ro- dirección a la variable
    // 2ndo- otros argumentos que seteamos en NULL
    pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex); //destruyo el mutex(si no lo hago da leaks)
    printf("Number of mails: %d\n", mails);
    return 0;
}
