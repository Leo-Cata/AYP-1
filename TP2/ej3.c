#include <stdio.h>

/*
Escriba un programa que permita realizar la suma de dos vectores de dimensión 5 utilizando
arreglos inicializados en el código (hardcoded) imprimiendo el resultado
*/
int main()
{
    int arrayOne[5] = { 1, 2, 3, 4, 5 };
    int arrayTwo[5] = { 1, 1, 1, 1, 1 };

    printf("{");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arrayOne[i] + arrayTwo[i]);
    }
    printf("}\0");
}