
///////////////////////////////// DATA RACES ///////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 

int mails = 0;
//mutex viene de MUtual Exclusion -> le dice a otros threads que solo el puede hacer cosas
pthread_mutex_t mutex; //declaro variable pero no inicializo

void* routine()
{
    for (int i = 0; i < 1000000; i++) 
    {
        //esta función hace que mutex lockee
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        //una vez puesto los locks y unlocks ya no tendria que tener data races 
    }
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
   return (NULL);
}

int main(int ac, char **av)
{
    //declaro variable de tipo pthread_t
    pthread_t t1 , t2;
    //inicializo el mutex aqui
    // 1ro- dirección a la variable
    // 2ndo- otros argumentos que seteamos en NULL
    pthread_mutex_init(&mutex, NULL);
    //pthread_create devuelve 0 si se ha creado el hilo correctamente
    //creo el hilo con esta función
    //1ero puntero a la variable anterior
    //2ndo NULL = tipo de hilo, por defecto
    //3ro funcion a ejecutar
    //4to argumento a pasar a la función anterior
    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0){
        return 2;
    }
    //pthread_join espera a que la routine del hilo finalize para seguir leyendo de main código
    //1ero identificador del hilo
    //2ndo valor de retorno -> NULL por defecto
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