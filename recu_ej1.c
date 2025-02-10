#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    // Declaramos pid
    pid_t pid = fork();

    // Control de error del fork
    if (pid == -1) {
        // Si fork devuelve -1, significa que hubo un error al crear el proceso
        perror("Error en fork");
        exit(1);  // Salimos del programa con un código de error
    }
    
    if (pid == 0) {
        // Este bloque se ejecuta solo en el proceso hijo
        printf("Hola, soy el proceso hijo con un PID de: %d\n y un PPID de: %d\n", getpid(), getppid());
    } else {
        // Este bloque se ejecuta solo en el proceso padre
        // Usamos wait para esperar que el hijo termine antes de continuar
        wait(NULL); // Esperamos a que el proceso hijo termine
        
        // Imprimimos información del proceso padre
        printf("Hola, soy el proceso padre con un PID de: %d\n y un PPID de: %d\n He creado un proceso hijo con PID: %d\n", getpid(), getppid(), pid);
    }

    return 0;
}
