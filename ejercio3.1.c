#include <stdio.h>   // Para printf()
#include <stdlib.h>  // Para exit() y atoi()
#include <sys/types.h> // Para pid_t
#include <unistd.h>  // Para fork() y getpid()

int main() {
    int num_hijos = 10;  // Número de hijos a crear
    pid_t pid;           // Variable para almacenar el PID de los hijos

    // Bucle para crear los procesos hijos
    for (int i = 0; i < num_hijos; i++) {
        pid = fork();  // Crea un nuevo proceso

        if (pid < 0) {  // Comprobar si hubo un error al crear el hijo
            perror("Error al crear el proceso hijo");
            exit(1);  // Terminar el programa con un código de error
        } else if (pid == 0) {  // Código que se ejecuta en el proceso hijo
            // Imprimir el PID del hijo y el número de hijos que ha creado el padre
            printf("Soy el hijo con PID %d, creado por mi padre.\n", getpid());
            printf("El número de hijos creados por mi padre es: %d\n", i + 1);
            exit(0);  // Terminar el proceso hijo
        }
        // Si el pid es mayor que 0, estamos en el proceso padre, no hacemos nada
    }

    // El padre puede realizar otras tareas aquí, si lo desea.
    // Por ejemplo, el padre puede esperar a que terminen todos los hijos.
    for (int i = 0; i < num_hijos; i++) {
        wait(NULL);  // Esperar a que cualquier hijo termine
    }

    printf("El padre ha creado %d hijos.\n", num_hijos);  // Imprimir el número total de hijos creados
    return 0;  // Terminar el programa correctamente
}
