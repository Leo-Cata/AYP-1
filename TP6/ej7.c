/*
Escribí un programa con una función recursiva que descomponga un número entero positivo N
dado como producto de números primos.
*/

#include <stdio.h>

int descomponerNumero(int* numero, int* primoInicial)
{
    // al llegar a 0 termina el programa
    if (*numero == 1) {
        return 1;
    }

    if ((*numero) % (*primoInicial) == 0) {
        *numero = (*numero) / (*primoInicial);
        printf("%d + ", *primoInicial);
    } else {
        (*primoInicial)++;
    }

    return descomponerNumero(numero, primoInicial);
}

int main()
{
    int enteroADescomponer = 22;
    int primoInicial = 2;

    descomponerNumero(&enteroADescomponer, &primoInicial);
}