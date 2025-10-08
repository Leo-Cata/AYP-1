/*
Indicá qué es lo que hace la siguiente función recursiva:
int f(int n)
{
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 0;
    } else {
        return f(n - 2);
    }
}
*/
#include <stdio.h>

// chequea si es par restando -2 con cada llamado, si al final el numero es 0, entonces es par, si es 1 es impar
int esPar(int n)
{
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 0;
    } else {
        return esPar(n - 2);
    }
}

int main()
{
    int numero = 4;

    if (esPar(numero)) {
        printf("%d es par", numero);
    } else {
        printf("%d es impar", numero);
    }
}