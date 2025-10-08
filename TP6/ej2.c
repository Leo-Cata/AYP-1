/*
Escribí un programa que calcule la potencia N-ésima de un número entero positivo M mediante una función recursiva
*/

#include <stdio.h>

int potenciaRecursiva(int numeroA, int numeroB)
{
    if (numeroB == 1) {
        return numeroA;
    }

    return numeroA * potenciaRecursiva(numeroA, numeroB - 1);
};

int main()
{
    int numeroA = 5, numeroB = 2;

    printf("%d", potenciaRecursiva(numeroA, numeroB));
}