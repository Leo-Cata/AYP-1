/*
Modificá el ejercicio E11TP1 para que utilice una función que determine si un número dado
es primo (devuelve 1) o no (devuelve 0) (PS) (PE N=10).
*/
#include <math.h>
#include <stdio.h>

int esPrimo(int numero)
{
    // si son iguales o menores a 1, no son primos
    if (numero <= 1) {
        return 0;
    }

    // si es el 2, es primo
    if (numero == 2) {
        return 1;
    }

    // y si son pares mayores a 2, no son primos
    if (numero % 2 == 0) {
        return 0;
    }

    // verifica los divisores impares desde 3 hasta la raiz 2 de numero
    for (int i = 3; i <= sqrt(numero); i++) {

        // si es divisible por i no es primo
        if (numero % i == 0) {
            return 0;
        }
    }

    // si el loop llega a finalizar, se concluye que el numero es primo
    return 1;
};

int main()
{
    // inicializa la variable
    int inputNumber;

    // pide un numero
    printf("ingrese un numero para determinar si es primo\n");
    scanf("%i", &inputNumber);

    // si la funcion devuelve true, osea 1, indica que el numero es primo
    // si no, si devuelve false, osea 0, indica que no es primo
    if (esPrimo(inputNumber) == 1) {
        printf("%i es primo", inputNumber);
    } else if (esPrimo(inputNumber) == 0) {
        printf("%i no es primo", inputNumber);
    }
};