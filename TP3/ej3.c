/*
Modificá la resolución del ejercicio 2 del TP Nº 1 (E2TP1)
para implementar una función que reciba un arreglo de caracteres
como parámetro (nombre) e imprima por pantalla el mensaje “¡Hola nombre!”.
*/
#include <stdio.h>
#define maxNameLength 50

// toma un array de tipo char e imprime el nombre
void imprimirSaludo(char nombre[])
{
    printf("Hola %s", nombre);
};

int main()
{
    // variable para el nombre
    char nombre[maxNameLength];

    // pregunta el nombre y lo toma
    printf("cual es tu nombre?\n");
    scanf("%s", &nombre);

    // funcion para imprimir el saludo
    imprimirSaludo(nombre);
};