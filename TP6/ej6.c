/*
Ejercicio 6. Considerando las monedas y billetes de curso legal disponibles en nuestro país, escribí un
programa que, mediante una función recursiva, calcule la cantidad mínima de billetes y monedas necesarias
para cubrir una suma dada. Por ejemplo, si la suma es $ 32.255 el programa debe indica “1 billete de veinte
mil, 1 billete de diez mil, 1 billete de dos mil, 1 billete de doscientos, 1 billete de cincuenta, 1 moneda de 5”.
*/

#include <stdio.h>

int cantidadMinimaBilletes(int* cantidad)
{
    if (*cantidad == 0) {
        return 1;
    }

    // if casos para cada valor de billetes el cual imprime y luego resta el valor
    // porque con switch no se pueden hacer comparaciones
    if (*cantidad >= 20000) {
        printf("1 billete de 20k\n");
        (*cantidad) = (*cantidad) - 20000;
    } else if (*cantidad >= 10000) {
        printf("1 billete de 10k\n");
        (*cantidad) = (*cantidad) - 10000;
    } else if (*cantidad >= 2000) {
        printf("1 billete de 2k\n");
        (*cantidad) = (*cantidad) - 2000;
    } else if (*cantidad >= 1000) {
        printf("1 billete de 1k\n");
        (*cantidad) = (*cantidad) - 1000;
    } else if (*cantidad >= 500) {
        printf("1 billete de 500\n");
        (*cantidad) = (*cantidad) - 500;
    } else if (*cantidad >= 100) {
        printf("1 billete de 100\n");
        (*cantidad) = (*cantidad) - 100;
    } else if (*cantidad >= 50) {
        printf("1 billete de 50\n");
        (*cantidad) = (*cantidad) - 50;
    } else if (*cantidad >= 20) {
        printf("1 billete de 20\n");
        (*cantidad) = (*cantidad) - 20;
    } else if (*cantidad >= 10) {
        printf("1 billete de 10\n");
        (*cantidad) = (*cantidad) - 10;
    } else if (*cantidad >= 5) {
        printf("1 billete de 5\n");
        (*cantidad) = (*cantidad) - 5;
    } else if (*cantidad >= 1) {
        printf("1 moneda de 1\n");
        (*cantidad) = (*cantidad) - 1;
    }

    return cantidadMinimaBilletes(cantidad);
}

int main()
{
    int montoDinero = 83455;

    cantidadMinimaBilletes(&montoDinero);
}