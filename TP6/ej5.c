/*
Escribí un programa que, usando una función recursiva, lea una cadena de caracteres
que contenga paréntesis izquierdos y derechos, e indique si los mismos están balanceados
(es decir, si cada paréntesis izquierdo tiene su correspondiente paréntesis derecho)
*/

#include <stdio.h>
#include <string.h>
#define maxOracion 100

int leerParentesis(char oracion[], int* parentesisIzqCount, int* parentesisDerCount)
{
    // si llego al final return
    if (oracion[0] == '\0') {
        printf("hay: %d '(' y %d ')', %s", *parentesisIzqCount, *parentesisDerCount, (*parentesisDerCount == *parentesisIzqCount ? "estan balanciados" : "no estan balanciados"));
        return 1;
    }

    // suma dependiendo de que parentesis encuentra
    //  el ++ tiene que esta por fuera de los parentesis, si no incremental el puntero y no el valor
    if (oracion[0] == '(') {
        (*parentesisIzqCount)++;
    }
    if (oracion[0] == ')') {
        (*parentesisDerCount)++;
    }

    // se llama asi misma
    return leerParentesis(&oracion[1], parentesisIzqCount, parentesisDerCount);
}

int main()
{

    char oracion[maxOracion] = "(es decir, (si cada paréntesis ((izquierdo tiene su correspond))i)ente ho)";
    int parentesisIzq = 0, parentesisDer = 0;

    leerParentesis(oracion, &parentesisIzq, &parentesisDer);
}