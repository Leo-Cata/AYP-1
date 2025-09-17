/*
Escribe un programa que implemente una función que modifique una variable tipo int
del programa principal, incrementando en una unidad su valor.
*/
#include <stdio.h>

void incrementar(int* n)
{
    (*n)++; // hace falta que este entre () para aumentar el valor en *n, y no la direccion
}
int main()
{
    int variable = 1;
    printf("antes de incrementar: %d\n", variable);

    incrementar(&variable);
    printf("despues de incrementar: %d", variable);
}