#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Librería necesaria para wait()

typedef unsigned long long int ull;  // Para manejar grandes cantidades de datos

// Función para verificar si un número es impar
// Devuelve 1 si es impar, 0 si es par
int isOdd(int num) {
    return num % 2;
}

// Función para verificar si un número es primo
// Devuelve 1 si el número es primo, 0 si no lo es
int checkPrime(int num) {
    if (num < 2) {
        return 0; // Los números menores a 2 no son primos
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0; // No es primo si es divisible por otro número
        }
    }
    return 1; // Es primo si pasa la comprobación
}

// Parte 1: Cálculos secuenciales
// Función para calcular la suma de los primos y la suma de los impares
void calculateSums() {
    ull primeSum = 0;
    ull oddSum = 0;

    // Sumar los números primos entre 1 y 1,000,000
    for (int i = 1; i <= 1000000; i++) {
        if (checkPrime(i)) {
            primeSum += i; // Si el número es primo, lo sumamos
        }
    }

    // Sumar los números impares entre 1 y 5,000,000
    for (int i = 1; i <= 5000000; i++) {
        if (isOdd(i)) {
            oddSum += i; // Si el número es impar, lo sumamos
        }
    }

    // Imprimir los resultados
    printf("Suma de los números primos entre 1 y 1,000,000: %llu\n", primeSum);
    printf("Suma de los números impares entre 1 y 5,000,000: %llu\n", oddSum);
}

// Parte 2: Programación concurrente con procesos
// Función que maneja la concurrencia de procesos para calcular las sumas en paralelo
void calculateConcurrently() {
    pid_t pid1, pid2;
    ull primeSum = 0, oddProduct = 1;

    // Crear el primer subproceso para la suma de números primos
    pid1 = fork();
    if (pid1 < 0) { // Verificamos si fork() falló
        perror("Error al crear el primer subproceso para la suma de primos");
        exit(1); // Salimos si el fork falló
    }
    if (pid1 == 0) {
        // Subproceso 1: Calcular la suma de números primos
        for (int i = 1; i <= 1000000; i++) {
            if (checkPrime(i)) {
                primeSum += i; // Sumar los primos encontrados
            }
        }
        printf("Suma de los números primos entre 1 y 1,000,000 (subproceso): %llu\n", primeSum);
        exit(0); // Terminamos el subproceso correctamente
    }

    // Crear el segundo subproceso para el producto de números impares
    pid2 = fork();
    if (pid2 < 0) { // Verificamos si fork() falló nuevamente
        perror("Error al crear el segundo subproceso para el producto de impares");
        exit(1); // Salimos si el fork falló
    }
    if (pid2 == 0) {
        // Subproceso 2: Calcular el producto de números impares
        for (int i = 1; i <= 5000000; i++) {
            if (isOdd(i)) {
                oddProduct *= i; // Multiplicamos los números impares
                // Limitar el producto para evitar desbordamiento
                if (oddProduct > 1000000000000) {
                    oddProduct = 1000000000000;  // Limitar el valor a un máximo
                    break; // Salir si el producto es demasiado grande
                }
            }
        }
        printf("Producto de los números impares entre 1 y 5,000,000 (subproceso): %llu\n", oddProduct);
        exit(0); // Terminamos el subproceso correctamente
    }

    // Esperar a que los dos procesos terminen
    wait(NULL); // Esperamos el primer subproceso
    wait(NULL); // Esperamos el segundo subproceso
}

// Función principal que organiza las partes
int main() {
    // Parte 1: Calcular las sumas de forma secuencial
    printf("Calculando de manera secuencial...\n");
    calculateSums();

    // Parte 2: Calcular en paralelo con procesos concurrentes
    printf("\nCalculando de manera concurrente...\n");
    calculateConcurrently();

    return 0;
}
