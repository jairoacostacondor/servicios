#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Variables para almacenar los PIDs de los procesos
    pid_t pidH1, pidH2, pidN1, pidN2;

    // Crear H1
    pidH1 = fork();
    if (pidH1 == -1) {
        // Verificamos si hubo un error al crear el proceso
        perror("Error en fork para H1");
        exit(1);
    }
    if (pidH1 == 0) { // Proceso H1
        printf("Hola, soy el hijo 1 con PID: %d y PPID: %d\n", getpid(), getppid());
        exit(1); // Código de retorno 1 para los hijos directos del padre
    }

    // Crear H2
    pidH2 = fork();
    if (pidH2 == -1) {
        // Verificamos si hubo un error al crear el proceso
        perror("Error en fork para H2");
        exit(1);
    }
    if (pidH2 == 0) { // Proceso H2
        printf("Hola, soy el hijo 2 con PID: %d y PPID: %d\n", getpid(), getppid());

        // Crear nietos N1 y N2
        pidN1 = fork();
        if (pidN1 == -1) {
            // Verificamos si hubo un error al crear el proceso
            perror("Error en fork para N1");
            exit(1);
        }
        if (pidN1 == 0) { // Proceso N1 (nieto)
            printf("Hola, soy el nieto 1 con PID: %d y PPID: %d\n", getpid(), getppid());
            exit(2); // Código de retorno 2 para los nietos
        }

        pidN2 = fork();
        if (pidN2 == -1) {
            // Verificamos si hubo un error al crear el proceso
            perror("Error en fork para N2");
            exit(1);
        }
        if (pidN2 == 0) { // Proceso N2 (nieto)
            printf("Hola, soy el nieto 2 con PID: %d y PPID: %d\n", getpid(), getppid());
            exit(2); // Código de retorno 2 para los nietos
        }

        // Espera a los nietos para evitar procesos zombies
        wait(NULL);
        wait(NULL);

        exit(1); // Código de retorno 1 para H2, ya que es un hijo del proceso padre
    }

    // Espera a H1 y H2 para evitar procesos zombies
    wait(NULL); // Espera a H1
    wait(NULL); // Espera a H2

    return EXIT_SUCCESS;
}
