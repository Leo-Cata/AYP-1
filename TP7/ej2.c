/*
Escribí un programa que genere un arreglo de 10.000 números enteros aleatorios entre 1 y 10.000.
A continuación el programa debe buscar de manera secuencial 10 números predefinidos (hardcodeados), indicando por cada número si se encuentra en el arreglo. Al finalizar el programa debe indicar cuánto tiempo (en milisegundos) llevó la búsqueda de los 10 números
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxLargo 100000000

int main()
{
    int* arrayConIntsRandom = malloc(maxLargo * sizeof(int));
    int numerosHardcodeados[10] = { 4821, 156, 7395, 8502, 314, 99673, 2458, 5991, 1025, 8740 };

    // genera una semilla random
    srand(time(NULL));

    // pone numeros al azar del 0 al 10k
    for (int i = 0; i < maxLargo; i++) {
        arrayConIntsRandom[i] = rand() % 100000000;
    }
    // obtiene el timepo de inicio
    clock_t start = clock();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= maxLargo; j++) {
            if (numerosHardcodeados[i] == arrayConIntsRandom[j]) {
                printf("se encontro %d en la posicion %d\n", numerosHardcodeados[i], j);
            } else if (j == maxLargo) {
                printf("no se encontro %d en el array\n", numerosHardcodeados[i]);
            }
        }
    }

    // y el tiempo de finalizacion
    clock_t end = clock();

    // calcula el tiempo con end - start / cpu clocks por segundo
    double tiempo = (end - start) / CLOCKS_PER_SEC;
    printf("Tiempo: %.8f segundos", tiempo);
}