/*
Modificá el programa del ejercicio anterior para que en vez de 10000 genere 100.000 números. Luego realizá las 10 búsquedas de forma secuencial primero, y binaria después. Observá cómo varía el tiempo de ejecución en cada caso
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxLargo 200000

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

void busquedaLineal(int numerosABuscar[], int arrayDondeBuscar[])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < maxLargo; j++) {
            if (numerosABuscar[i] == arrayDondeBuscar[j]) {
                printf("Se encontro %d en posicion %d\n", numerosABuscar[i], j);
            }
        }
    }
}

int busquedaBinaria(int numerosABuscar[], int ArrayDondeBuscar[])
{

    for (int i = 0; i < 10; i++) {
        // variables para llevar donde esta el inicio/final y la mitad
        int inicio = 0;
        int fin = maxLargo - 1;
        int mitad = (inicio + fin) / 2;
        int encontrado = false;

        // en cada loop, setea la mitdad
        // si el numero que se esta buscando es menor a la mitad del array ordenado
        // setea el fin igual a la mitdad -1, si es la reves el inicio igual a la mitad +1
        // en el siguiente loop el array va a ser la mitad de largo
        while (inicio <= fin) {
            mitad = (inicio + fin) / 2;
            if (numerosABuscar[i] < ArrayDondeBuscar[mitad]) {
                fin = mitad - 1;
            } else if (numerosABuscar[i] > ArrayDondeBuscar[mitad]) {
                inicio = mitad + 1;
            } else {
                printf("Se encontro %d en posicion %d\n", numerosABuscar[i], mitad);
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            printf("No se encontro %d\n", numerosABuscar[i]);
        }
    }
}

int main()
{
    int* arrayConIntsRandom = malloc(maxLargo * sizeof(int));
    int numerosHardcodeados[10] = { 4821, 156, 7395, 8502, 314, 99673, 2458, 5991, 1025, 8740 };

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
    printf("Tiempo de ordenamiento: %.8f segundos\n\n", tiempo);

    // mide el tiempo de busqueda lineal
    start = clock();
    busquedaLineal(numerosHardcodeados, arrayConIntsRandom);
    end = clock();

    tiempo = (end - start) / CLOCKS_PER_SEC;
    printf("\n\nTiempo de busqueda lineal: %f segundos\n\n", tiempo);

    start = clock();
    busquedaBinaria(numerosHardcodeados, arrayConIntsRandom);
    end = clock();

    tiempo = (end - start) / CLOCKS_PER_SEC;

    printf("\n\nTiempo de busqueda binaria: %f segundos\n\n", tiempo);

    free(arrayConIntsRandom);
}
