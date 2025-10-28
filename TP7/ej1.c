/*
Escribí un programa que, a partir de un arreglo hardcodeado de 10 números enteros, indique si el
mismo se encuentra ordenado o no. Investigá cuál es el mejor algoritmo para determinar si un arreglo está o
no en orden.
*/

#include <stdio.h>

int main()
{
    int numerosDesordenados[10] = { 42, 43, 44, 45, 46, 11, 48, 49, 50, 50 };

    // primer loop para tomar un elemento, y el segundo para recorrer por todos los demas comparando
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (numerosDesordenados[i] > numerosDesordenados[j]) {
                printf("Esta desordenado, %d es mayor que %d", numerosDesordenados[i], numerosDesordenados[j]);
                return 0;
            }
        }
    }
    printf("esta ordenado");
}