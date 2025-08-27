#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numberArray[10], randomNumb, repeatedArray[10] = { 0 }, counter;

    // crea una semilla para los valores random
    srand(time(NULL));

    while (counter < 10) {
        randomNumb = rand() % 11;

        /*
        si el numero random obtenido no esta marcado como 1 en el array de numeros repetidos
        lo agrega al array final, marca como repetido y lo imprime
        */
        if (!repeatedArray[randomNumb]) {
            numberArray[counter] = randomNumb;
            repeatedArray[randomNumb] = 1;

            printf("%d ", numberArray[counter]);
            counter++;
        }
    }
}