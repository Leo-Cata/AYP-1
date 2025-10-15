/*
Usando recursividad escribí un programa que dado un número entero positivo N imprima en
pantalla una pirámide de altura N “dibujando” cada nivel de la pirámide con los números de 1 hasta N. Por
ejemplo, si el usuario ingresa 5, el programa debe imprimir lo siguiente:
    1
   2 2
  3 3 3
 4 4 4 4
5 5 5 5 5
*/

#include <stdio.h>

int printPiramide(int largo)
{
    if (largo == 0) {
        return 1;
    }

    // loop para impormer espacios
    for (int i = 0; i < largo - 1; i++) {
        printf(" ");
    }

    // loop para imprimir los numeros
    for (int i = largo; i >= 0; i--) {

        printf("A");
    }
    printf("\n");

    return printPiramide(largo - 1);
};

int main()
{
    int piramideLargo = 5;

    printPiramide(piramideLargo);
}