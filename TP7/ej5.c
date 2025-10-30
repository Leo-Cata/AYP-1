/*
A partir del ejercicio anterior, con 100.000 números generados de manera aleatoria, realizá el
ordenamiento de los mismos mediante los siguientes métodos:
A. Burbujeo
B. Merge sort
C. Quick sort
Imprimí el tiempo de ejecución de cada método.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxLargo 10000000

int bubbleSort(int* arrayAOrdenar, int inicio, int final)
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

int mergeSort(int* arrayAOrdenar, int inicio, int fin)
{
    // is el inicio es mayor o igual que el fin, aka caso base termina
    if (inicio >= fin) {
        return 1;
    }

    // calcula la mitad y llama recursivamente, con la mitad de la izq y la de la derecha
    int mitad = inicio + (fin - inicio) / 2;
    mergeSort(arrayAOrdenar, inicio, mitad);
    mergeSort(arrayAOrdenar, mitad + 1, fin);

    // calcula el tamanio para los subarrays
    int tamanioIzq = mitad - inicio + 1;
    int tamanioDer = fin - mitad;

    // asigna memorio a los arrays
    int* arrayIzq = (int*)malloc(tamanioIzq * sizeof(int));
    int* arrayDer = (int*)malloc(tamanioDer * sizeof(int));
    if (arrayIzq == NULL || arrayDer == NULL) {
        printf("No se pudo asignar memoria\n");
        exit(1);
    }

    // para cada sub array, le asigna los valores de la mitad para un lado y de la otra para el otro
    for (int i = 0; i < tamanioIzq; i++) {
        arrayIzq[i] = arrayAOrdenar[inicio + i];
    }
    for (int i = 0; i < tamanioDer; i++) {
        arrayDer[i] = arrayAOrdenar[mitad + 1 + i];
    }

    // indices para el loop
    int indiceUno = 0, indiceDos = 0, indiceArrayOriginal = inicio;
    // loopea chequeando que hayan elementos en los arrays
    // si los hay, chequea si el elemento de la izq es menor al de la derecha
    // si lo es, lo asigna al array original
    // si es mayor copia el de la derecha
    // luego incrementa los vals de los indices
    // osea los mergea
    while (indiceUno < tamanioIzq && indiceDos < tamanioDer) {
        if (arrayIzq[indiceUno] <= arrayDer[indiceDos]) {
            arrayAOrdenar[indiceArrayOriginal] = arrayIzq[indiceUno];
            indiceArrayOriginal++;
            indiceUno++;
        } else {
            arrayAOrdenar[indiceArrayOriginal] = arrayDer[indiceDos];
            indiceArrayOriginal++;
            indiceDos++;
        }
    }

    // corre cuando uno de los arrays anteriores haya terminado primero
    while (indiceUno < tamanioIzq) {
        arrayAOrdenar[indiceArrayOriginal] = arrayIzq[indiceUno];
        indiceArrayOriginal++;
        indiceUno++;
    }
    while (indiceDos < tamanioDer) {
        arrayAOrdenar[indiceArrayOriginal] = arrayDer[indiceDos];
        indiceArrayOriginal++;
        indiceDos++;
    }

    // libera el espacio en mem de ambos
    free(arrayIzq);
    free(arrayDer);
}

// quick sort
int quickSort(int* arrayAOrdenar, int inicio, int fin)
{
    // da el promedio de los 3 valores
    if (inicio < fin) {
        // calcula el valor medio
        int mitad = inicio + (fin - inicio) / 2;
        int primerElemento = arrayAOrdenar[inicio];
        int elementoMedio = arrayAOrdenar[mitad];
        int ultimoElemento = arrayAOrdenar[fin];

        // calcula cual de los 3 elementos es el del medio y lo setea como pivote
        int pivoteIndice;
        if ((primerElemento < elementoMedio && elementoMedio < ultimoElemento) || (ultimoElemento < elementoMedio && elementoMedio < primerElemento)) {
            pivoteIndice = mitad;
        } else if ((elementoMedio < primerElemento && primerElemento < ultimoElemento) || (ultimoElemento < primerElemento && primerElemento < elementoMedio)) {
            pivoteIndice = inicio;
        } else {
            pivoteIndice = fin;
        }

        int pivoteValor = arrayAOrdenar[pivoteIndice];

        // mueve el valor en la posicion del pivote al final, y la del final a la posicion del pivote
        int valorTemporal = arrayAOrdenar[pivoteIndice]; // 1 [2] 3
        arrayAOrdenar[pivoteIndice] = arrayAOrdenar[fin]; // 1 3 3
        arrayAOrdenar[fin] = valorTemporal; // 1 3 2

        int indice = inicio;

        // para cada elemento desde el inicio hasta el fin
        // si el valor en [i] es igual o menor al pivote
        //  incrementa el indice
        // asigna temporalmente el valor en el indice
        //  asigna el valor en posicion [indice] al valor en [i]
        // y asigna el valor en [i] al valor temporal
        // hace que todos los elementos mayores al pivote queden de un lado, y los menores al otro
        for (int i = inicio; i < fin; i++) {
            if (arrayAOrdenar[i] <= pivoteValor) {
                valorTemporal = arrayAOrdenar[i];
                arrayAOrdenar[i] = arrayAOrdenar[indice];
                arrayAOrdenar[indice] = valorTemporal;
                indice++;
            }
        }

        // setea el valor del indice + 1 a la var temp
        // setea el valor en indice +1 con el valor del final
        // setea el valor en [fin] con el valor temporal
        // y guarda donde esta el pivote como indice +1
        valorTemporal = arrayAOrdenar[indice];
        arrayAOrdenar[indice] = arrayAOrdenar[fin];
        arrayAOrdenar[fin] = valorTemporal;
        int indiceDondeQuedoPivote = indice;

        quickSort(arrayAOrdenar, inicio, indiceDondeQuedoPivote - 1);
        quickSort(arrayAOrdenar, indiceDondeQuedoPivote + 1, fin);
        return 0;
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
    int opcion;
    printf("0 bubble, 1 merge, 2 quick ");
    scanf("%d", &opcion);
    clock_t start;
    clock_t end;

    // puntero a funcion
    int (*funcionDeSorting)(int*, int, int) = NULL;

    switch (opcion) {
    case 0:
        funcionDeSorting = bubbleSort;
        break;
    case 1:
        funcionDeSorting = mergeSort;
        break;
    case 2:
        funcionDeSorting = quickSort;
        break;
    default:
        break;
    }
    start = clock();
    funcionDeSorting(arrayConIntsRandom, 0, maxLargo - 1);
    end = clock();

    // calcula el tiempo con end - start / cpu clocks por segundo
    double tiempo = (end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo de ordenamiento: %f \n", tiempo);

    for (int i = 0; i < maxLargo - 1; i++) {
        if (arrayConIntsRandom[i] > arrayConIntsRandom[i + 1]) {
            printf("esta mal ordenado che");
            return 0;
        }
    }
    printf("esta re piola");

    free(arrayConIntsRandom);
}
