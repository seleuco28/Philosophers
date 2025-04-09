
///////////////////////////////// INTRODUCCION /////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //libreria especifica para hilos

////////////////////////////////COSAS IMPORTANTES////////////////////////////////

//los threads comparten memoria (los procesos no), y por eso se dan los data races

void* routine()
{
    printf("Test from threads\n");
    sleep(3);
    printf("Ending thread\n");
}

int main(int ac, char **av)
{
    //declaro variable de tipo pthread_t 
    pthread_t t1 , t2;
    //Estas funciones de abajo, retornan un int "0" si está bien, con el if las hago mas consistentes
    //creo el hilo con esta función
    //1ero puntero a la variable anterior
    //2ndo para setear en default
    //3ro funcion a ejecutar
    //4to argumento a pasar a la función anterior
    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0){
        return 2;
    }
    //igual que con los procesos, tengo que esperar a que el hilo termine su ejecución
    //esta función es el wait pero para hilos
    if (pthread_join(t1, NULL) != 0){
        return 3;
    }
    if (pthread_join(t2, NULL) != 0){
        return 4;
    }
    return 0;
}