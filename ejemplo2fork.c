#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	//en este ejercicio queremos obtener una jerquia de procesos es decir que tendrian que salir uno detras de otro en un orden en especifico; nos tiene que imprimir en un orden concreto


	//declaramos las variables en este caso tendremos 5== 1 PADRE, 2 HIJOS y 2 NIETOS
	pid_t pidPADRE, pidHIJO1, pidHIJO2, pidNIETO1, pidNIETO2;
	//HACEMOS FORK AL PADRE
	pidPADRE = fork();
	//HACEMOS UN IF PARA IGUALARLO A 0 YA QUE ES ALGO IMPOSIBLE PERO QUEREMOS ESO PARA QUE SALGA EL HIJO1 PRIMERO


	if(pidPADRE == 0){
		printf("Hola soy hijo1 con el un PID de : %d\n y con un PPID de %d\n",getpid(), getppid());
		exit(1);

		}else{
			//hacemos fork al HIJO 1 
			pidHIJO1 = fork();  
			if(pidHIJO1 == 0){
				printf("Hola soy HIJO2 con un PID de: %d\n y con un PPID de %d\n",getpid(), getppid());
				exit(2);

			}
			pidHIJO2 = fork();
			if(pidHIJO2 == 0){
				printf("Hola soy NIETO1  con un PID de %d\n y con un PPID de %d\n",getpid(), getppid());
				exit(3);

			}
			pidNIETO1 = fork();
			if(pidNIETO1 == 0){
				printf("Hola soy NIETO2 con un PID de %d\n y con un PPID de %d\n",getpid(),getppid());
				exit(4);

			}


		}
	return EXIT_SUCCESS;
}
