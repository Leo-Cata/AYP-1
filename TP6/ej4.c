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

int printPiramide(int largoInicial, int largoTotal)
{
    // si el largo inicial, osea 1+1 cada iteracion es mayor que el total buscado termina
    if (largoInicial > largoTotal) {
        return 1;
    }

    // imprime espacios
    for (int i = 0; i < largoTotal - largoInicial; i++) {
        printf(" ");
    }

    // imprime tantos numeros como el numero inicial + 1 cada interacion
    for (int i = 0; i < largoInicial; i++) {
        printf("%d ", largoInicial);
    }

    printf("\n");

    return printPiramide(largoInicial + 1, largoTotal);
};

int main()
{
    int piramideLargo = 5;

    printPiramide(1, piramideLargo);
}