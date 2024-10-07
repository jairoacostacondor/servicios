#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
	//declaramos las varables de padre e hijo
	
	//inciamos el fork
	pid_t pid = fork();
	if(pid == 0) {
		//sabemos que todos los procesos hijos tiene un pid de 0 por eso al igualarlo sabemos que es el hijo
		printf("Holaaa soy el proceso HIJO con un PID de: %d\n y un PPID: %d\n",getpid(),getppid());
	}
	else{
		//Ahora es el turno del padre
		printf("Holaaa soy el PADRE con un PID de: %d\n y un PPID de: %d\n y he creado un proceso HIJO con PID: %d\n",getpid(),getppid(),pid);
	}
	return 0;
}