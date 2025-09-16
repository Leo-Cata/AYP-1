/*
Modificá el programa del ejercicio E13TP1 para implementar dos funciones,
una para calcular elproducto de dos números como sumas sucesivas
y otra para calcular la potencia entre dos números N y Mcomo productos sucesivos
*/

#include <stdio.h>

// funcion que calcula el producto con los valores ingresados
// y devuelve despues de sumar factorN+factorN una cantidad de factorM veces
int producto(int factorN, int factorM)
{
    int productoResultado = 0;
    for (int i = 0; i < factorM; i++) {
        productoResultado = productoResultado + factorN;
    }

    return productoResultado;
};

// funcion que calcula la potiencia de dos valores
//  y devuelve el resultado como la potencia mediante el producto sucesivo de N*N M veces
int potencia(int base, int exponente)
{
    int potenciaResultado = 1;
    for (int i = 0; i < exponente; i++) {
        potenciaResultado = potenciaResultado * base;
    }
    return potenciaResultado;
};

int main()
{
    int numeroN, numeroM, resultadoProducto = 0;
    long long int resultadoPotencia = 0;

    printf("ingrese dos numeros naturales para calcular el primero elevado al segundo\n");
    scanf("%i %i", &numeroN, &numeroM);

    resultadoProducto = producto(numeroN, numeroM);
    printf("El producto de %i y %i, es: %i\n", numeroN, numeroM, resultadoProducto);

    resultadoPotencia = potencia(numeroN, numeroM);
    printf("potencia potencia de %i y %i, es: %lld", numeroN, numeroM, resultadoPotencia);
}