/*
Declara un arreglo ‘a’ de 5 enteros y un puntero a entero ‘p’. Asigna la dirección de memoria del
primer elemento del arreglo al puntero. Luego, utiliza el puntero para imprimir todos los elementos del
arreglo
*/

#include <stdio.h>

int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int* p = &a[0];

    printf("%d,%d,%d,%d,%d", *p, *p + 1, *p + 2, *p + 3, *p + 4);
}