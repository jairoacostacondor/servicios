#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;

    // Creaamos un proceso hijo
    pid = fork();
    if (pid == -1) {
        // Error al crear el proceso hijo
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) { // Proceso padre ya que si o si es mayor que 0
        printf("Hola, ¿qué tal?\n"); // El padre pregunta
        wait(NULL); // Esperar a que el hijo termine
    } else { // Proceso hijo
        printf("\tSoy el proceso hijo, mi PID es %d\n", getpid());
        printf("Estoy bien, gracias por preguntar\n"); // El hijo responde
    }

    printf("Soy el proceso padre, mi PID es %d\n", getpid()); // Ultima respuesta
    return 0;
}

 
