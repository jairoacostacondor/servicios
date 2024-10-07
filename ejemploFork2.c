#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    //en este ejercicio queremos obtener una jerquia; nos tiene que imprimir en un orden concreto
    //declaramos las variables en este caso tendremos 5== 1 PADRE, 2 HIJOS y 2 NIETOS

    pid_t pidH1, pidH2, pidN1, pidN2;

    // Crear H1

    pidH1 = fork();
    if (pidH1 == 0) { // Proceso H1
        printf("Hola, soy el hijo 1 con PID: %d y PPID: %d\n", getpid(), getppid());
        exit(1);
    }

    // Crear H2

    pidH2 = fork();
    if (pidH2 == 0) { // Proceso H2
        printf("Hola, soy el hijo 2 con PID: %d y PPID: %d\n", getpid(), getppid());

    // Crear nietos N1 y N2
        pidN1 = fork();
        if (pidN1 == 0) { // Proceso H21
            printf("Hola, soy el nieto 1 con PID: %d y PPID: %d\n", getpid(), getppid());
            exit(2);
        }

        pidN2 = fork();
        if (pidN2 == 0) { // Proceso H22
            printf("Hola, soy el nieto 2 con PID: %d y PPID: %d\n", getpid(), getppid());
            exit(2);
        }

        // Espera a los nietos
        wait(NULL);
        wait(NULL);
        exit(1); // H2 termina
    }

    // Espera a H1 y H2
    wait(NULL);
    wait(NULL);

    return EXIT_SUCCESS;
}
