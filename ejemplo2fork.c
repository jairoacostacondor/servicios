#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	//en este ejercicio queremos obtener una jerquia; nos tiene que imprimir en un orden concreto
	pid_t pidPADRE, pidHIJO1, pidHIJO2, pidNIETO1, pidNIETO2;
	pidPADRE = fork();
	if(pidPADRE == 0){
		printf("Hola soy hijo1 con el un PID de : %d\n y con un PPID de %d\n",getpid(), getppid());


	}




	return 0;
}
