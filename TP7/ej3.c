/*
Modificá el programa del ejercicio anterior para que, luego de generar aleatoriamente los 10.000 números, los ordene mediante el método de burbujeo y luego ejecute la búsqueda de forma binaria. Nuevamente, imprimí al terminar el tiempo en milisegundos que llevó realizar las 10 búsquedas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxLargo 50000

void bubbleSort(int* arrayAOrdenar)
{
    // lleva la cuanta de cuando se intercambia
    int huboIntercambio = 1;

    // variable para que tenga un numero de manera temporal
    int valorTemp;

    // mientras que no se llegue al largo, e intercambio =1
    for (int i = 0; huboIntercambio && i < maxLargo - 1; i++) {

        // lo setea a 0
        huboIntercambio = 0;

        // en cada pasada, pregunta si el numero actual es mayor al que le sigue, si lo es los intercambia, sucesivamente
        // cuando no hay intercambio,
        for (int j = 0; j < maxLargo - i - 1; j++) {
            if (arrayAOrdenar[j] > arrayAOrdenar[j + 1]) {
                valorTemp = arrayAOrdenar[j];
                arrayAOrdenar[j] = arrayAOrdenar[j + 1];
                arrayAOrdenar[j + 1] = valorTemp;
                huboIntercambio = 1;
            }
        }
    }
}

int main()
{
    int* arrayConIntsRandom = malloc(maxLargo * sizeof(int));

    // genera una semilla random
    srand(time(NULL));

    // pone numeros al azar del 0 al 10k
    for (int i = 0; i < maxLargo; i++) {
        arrayConIntsRandom[i] = rand() % maxLargo;
    }

    // obtiene el timepo de inicio
    clock_t start = clock();

    bubbleSort(arrayConIntsRandom);

    // y el tiempo de finalizacion
    clock_t end = clock();

    // calcula el tiempo con end - start / cpu clocks por segundo
    double tiempo = (end - start) / CLOCKS_PER_SEC;
    printf("Tiempo: %.8f segundos", tiempo);

    free(arrayConIntsRandom);
}