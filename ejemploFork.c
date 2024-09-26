#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	pid_t pid, Hijo_pid;
	pid = fork(); //crea un subproceso
		      //fork hace que se cree una bifurcacion osea que se crean 2 partes y ejecutan el mismo cod:w:q
	
	if(pid == 0){
		//el proceso hijo
		printf("soy el hijo\n\tPID:%d\n\tPPID:%d\n",getpid(),getppid());
	}
	else{
		printf("Soy el padre.\n\tPID:%d\n\tPPID:%d\n\tPID Hijo: %d",getpid(),getppid(),pid);
		printf("\t Variable PID: %d", pid);
			//proceso padre
	}
	printf("hola\n");
	printf("hola\n");
	return 0;
}
