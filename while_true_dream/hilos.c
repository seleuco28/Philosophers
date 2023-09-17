
/*  PROGRAMA QUE HACE WhileTrueDream -- en este video --
        https://www.youtube.com/watch?v=NAKrOZCcJ4A
*/


#include <pthread.h> //libreria para hilos
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void *thread_routine(void *ac)
{
    int nr_lines = *((int *)ac); //casteamos para que pase de void a int* y luego otro '*' para tomar su valor 
    int fd;
    char buff[] = "Nueva linea \n";
    printf("El hilo comienza a ejecutarse... \n");

    for (int i = 0; i < nr_lines; i++)
    {
        // O_APPEND -- para que cada vez que se abra haya una nueva linea, comprobar esto.
        fd = open("/Users/alvarovelazquez/Desktop/philo/while_true_dream/hola.txt", O_WRONLY|O_APPEND);
        write(fd, buff, sizeof(buff) - 1); //no queremos el \0
        close (fd);
    }

}

int main(int ac, char **av)
{
    pthread_t thread1; //dato de tipo pthread_t, el identificador del hilo
    int value = 0; //esto es para que si no pones argumentos de entrada, no escriba nada
    if (ac > 1)
        value = atoi(av[1]);
    else
    {
        printf("Se te olvido pasar un argumento, numero de lineas a estribir \n");
    }
    /*FUNCION PARA CREAR HILO
    Argumentos:
    1- Puntero al identificador del hilo
    2- Los atributos del hilo -> NULL para que sean los de defecto
    3- 'Start routine':Rutina a ejecutar cuando se cree el hilo
    4- Argumentos de entrada de la start routine del hilo
    ** pthread_create() tiene exito y se crea, nos devuelve 0 
    */
    if (0 != pthread_create(&thread1, NULL, thread_routine, &value))
        return -1;
    /* FUNCION PARA QUE MAIN ESPERE A QUE ACABE EL HILO FINALIZE
    Argumentos:
    1- El identificador del hilo
    2- El valor de retorno (no lo utiliza = NULL)
    */
    pthread_join(thread1, NULL);

    return 0;
}