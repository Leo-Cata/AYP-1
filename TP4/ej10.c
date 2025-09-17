/*
Modificá el programa del ejercicio E3TP2 para implementar una función que reciba dos arreglos de números enteros de dimensión 5 y devuelvan otro arreglo del mismo tamaño
*/
#include <stdio.h>
void vectorSum(int* pointerArrayOne, int* pointerArrayTwo)
{
    printf("{");
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            printf("%d}", pointerArrayOne[i] + pointerArrayTwo[i]);
        } else {
            printf("%d, ", pointerArrayOne[i] + pointerArrayTwo[i]);
        }
    }
}
int main()
{
    /*
    harcoded arrays para sumar
    */
    int arrayOne[5] = { 1, 2, 3, 4, 5 };
    int arrayTwo[5] = { 1, 1, 1, 1, 1 };

    vectorSum(arrayOne, arrayTwo);
}