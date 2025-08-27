#include <stdio.h>

/*
Escriba un programa que permita realizar la suma de dos vectores de dimensión 5 utilizando
arreglos inicializados en el código (hardcoded) imprimiendo el resultado
*/
int main()
{
    /*
    harcoded arrays para sumar
    */
    int arrayOne[5] = { 1, 2, 3, 4, 5 };
    int arrayTwo[5] = { 1, 1, 1, 1, 1 };

    /*
    loopea 5 veces, sumando las pocisiones, imprimiendo una coma excepto en el ultimo valor
    */
    printf("{");
    for (int i = 0; i < 5; i++) {
        if(i==4){
        printf("%d}", arrayOne[i] + arrayTwo[i]);
        }else{
            printf("%d, ", arrayOne[i] + arrayTwo[i]);
        }
    }
}