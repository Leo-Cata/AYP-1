#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define arrayLength 20

/*
Escriba un programa que genere un arreglo de 20 números enteros aleatorios entre 0 y 9, lo
imprima y luego elimine los duplicados, imprimiendo el arreglo resultante al finalizar
*/
int main()
{
    // inicializacion de variables
    int randomNumbersArray[arrayLength], randomNumber;
    // crea semilla para el numero random
    srand(time(NULL));

    /*
    imprime una { para simular un array en pantalla
    */
    printf("{");
    for (int i = 0; i < arrayLength; i++)
    {
        // para el primer array, ingresa 20 numeros al azar del 0-9
        randomNumber = rand() % 10;
        randomNumbersArray[i] = randomNumber;

        // si es el ultimo elemento, se imprime en pantalla con } para simular la variable
        // si no, imprime con ,
        if (i == arrayLength - 1)
        {
            printf("%d}\n", randomNumbersArray[i]);
        }
        else
        {
            printf("%d, ", randomNumbersArray[i]);
        }
    }

    /*
    inicializacion de las variables para el array sin repeticiones,
    y un array contador de numeros repetidos
    */
    int unrepeatedArray[arrayLength], countArray[10] = {0};

    printf("array sin repeticiones: {");

    for (int i = 0; i < arrayLength; i++)
    {
        // asigna el numero de la posicion i a una nueva variable
        int numberInRandomArray = randomNumbersArray[i];

        /*
        luego si el numero asignado anteriormente es == 0 en el array contador
        agrega ese numero al array sin numeros repetidos,
        setea ese numero no repetido como 1 en el array contador para que no se repita
        e imprime el numero en pantalla, con "," o con una "}" para simular el array
        */
        if (countArray[numberInRandomArray] == 0)
        {
            unrepeatedArray[i] = numberInRandomArray;
            countArray[numberInRandomArray] = 1;
            printf("%d ", unrepeatedArray[i]);
        }
    }
    printf("}\n");
}
