#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	//declaramos las varables de padre e hijo
	
	//inciamos el fork
	pid_t 
	if(pid == 0) {
		//sabemos que todos los procesos hijos tiene un pid de 0 por eso al igualarlo sabemos que es el hijo
		printf("Holaaa soy el proceso HIJO con un PID de: %d\n",id);
	}
	else{
		printf("Holaaa soy el PADRE con un PID de: %d\n",id);
	}

	return 0;
}
