#include <stdio.h>      // Para printf() y perror()
#include <stdlib.h>     // Para exit()
#include <sys/types.h>  // Para pid_t
#include <unistd.h>     // Para fork(), getpid(), getcwd()
#include <time.h>       // Para time() y ctime()

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
            // Obtener el PID del hijo
            pid_t hijo_pid = getpid();

            if (hijo_pid % 2 == 0) {  // Verificar si el PID es par
                // Obtener la fecha y hora actual
                time_t t;               // Variable para almacenar el tiempo
                time(&t);              // Obtener el tiempo actual
                printf("Soy el hijo con PID %d (par). La fecha y hora actual es: %s", hijo_pid, ctime(&t));
            } else {  // Si el PID es impar
                // Obtener el directorio actual
                char directorio_actual[1024];  // Buffer para el directorio actual
                if (getcwd(directorio_actual, sizeof(directorio_actual)) != NULL) {
                    printf("Soy el hijo con PID %d (impar). El directorio actual es: %s\n", hijo_pid, directorio_actual);
                } else {
                    perror("Error al obtener el directorio actual");
                }
            }
            exit(0);  // Terminar el proceso hijo
        }
        // Si el pid es mayor que 0, estamos en el proceso padre, no hacemos nada
    }

    // El padre puede esperar a que terminen todos los hijos.
    for (int i = 0; i < num_hijos; i++) {
        wait(NULL);  // Esperar a que cualquier hijo termine
    }

    printf("El padre ha creado %d hijos.\n", num_hijos);  // Imprimir el número total de hijos creados
    return 0;  // Terminar el programa correctamente
}
