#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumb, repeatedArray[10] = { 0 }, counter;

    // crea una semilla para los valores random
    srand(time(NULL));

    /*
    se calcula 10 veces un numero random, y se suma +1 a cada repeticion
    loopeado 10 veces por un total de 100 veces
    */
    for (int i = 0; i < 10; i++) {
        counter = 0;
        while (counter < 10) {
            randomNumb = rand() % 11;
            repeatedArray[randomNumb]++;
            counter++;
        }
    }

    for (int i = 0; i < 11; i++) {
        printf("el numero %d se ha repetido: %d\n", i, repeatedArray[i]);
    }
}