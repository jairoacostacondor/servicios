#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h> // Para la definición de pid_t

int main() {
    pid_t pid;  // Usamos pid_t para representar el ID del proceso correctamente

    // Intentamos crear un proceso hijo
    pid = fork();
    
    // Comprobamos si hubo un error al crear el proceso hijo
    if (pid == -1) {
        // Si pid == -1, significa que hubo un problema al crear el proceso
        perror("Error al crear el proceso hijo con fork()");
        exit(1);  // Salimos del programa con código de error
    }

    if (pid > 0) { // Estamos en el proceso padre
        printf("Hola, ¿qué tal?\n"); // El padre pregunta
        wait(NULL); // El padre espera a que el hijo termine antes de continuar

    } else { // Estamos en el proceso hijo
        printf("\tSoy el proceso hijo, mi PID es %d\n", getpid());
        printf("Estoy bien, gracias por preguntar\n"); // El hijo responde al padre
    }

    // Esta línea se ejecuta en ambos procesos (padre e hijo)
    printf("Soy el proceso con PID %d, y he terminado mi trabajo.\n", getpid()); 

    return 0;
}
