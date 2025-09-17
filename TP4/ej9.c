/*
Modificá el programa del ejercicio E1TP2 para que implemente una función que reciba el arreglo de números enteros y un número entero y determine si el número dado está o no en el arreglo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxArrayLength 25

// funcion que recibe el array
void checkForNumber(int* pointerRepeatedArray)
{
    // le pregunta un numero al usuario entre 0 y maxArraylength
    int userNumberToFind;
    printf("ingrese un numero del 0 al %d para buscar\n", maxArrayLength);
    scanf("%d", &userNumberToFind);

    // si se encuentra, imprime, no si imprime que no se encontro
    if (pointerRepeatedArray[userNumberToFind]) {
        printf("%d se encuentra %d veces", userNumberToFind, pointerRepeatedArray[userNumberToFind]);
    } else {
        printf("%d no se encuentra en el array", userNumberToFind);
    };
};

int main()
{
    int randomNumb, repeatedArray[maxArrayLength] = { 0 }, counter;

    // crea una semilla para los valores random
    srand(time(NULL));

    /*
    se calcula 10 veces un numero random, y se suma +1 a cada repeticion
    */
    for (int i = 0; i <= maxArrayLength; i++) {

        randomNumb = rand() % maxArrayLength + 1;
        repeatedArray[randomNumb]++;
    }

    for (int i = 0; i <= maxArrayLength; i++) {
        printf("el numero %d se ha repetido: %d\n", i, repeatedArray[i]);
    }

    checkForNumber(repeatedArray);
}