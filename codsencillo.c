#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main() {
    pid_t pid = fork();  // Crear un nuevo proceso hijo

    if (pid < 0) {  // Comprobar si hubo un error al crear el hijo
        perror("Error al crear el proceso hijo");
        return 1;
    } else if (pid == 0) {  // Código del proceso hijo
        srand(time(NULL));  // Inicializar el generador de números aleatorios
        int duracion = rand() % 11;  // Generar un número aleatorio entre 0 y 10
        printf("Soy el hijo con PID %d y dormiré %d segundos.\n", getpid(), duracion);
        sleep(duracion);  // Dormir el tiempo aleatorio
        printf("Hijo con PID %d ha terminado.\n", getpid());
        exit(0);  // Salir del hijo
    } else {  // Código del proceso padre
        int status;
        wait(&status);  // Esperar a que el hijo termine
        printf("El proceso hijo ha terminado. PID: %d\n", pid);
    }

    return 0;  // Finalizar el programa
}
