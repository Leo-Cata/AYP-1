/*
Escribí un programa que, usando una función recursiva, lea una cadena de caracteres
que contenga paréntesis izquierdos y derechos, e indique si los mismos están balanceados
(es decir, si cada paréntesis izquierdo tiene su correspondiente paréntesis derecho)
*/

#include <stdio.h>
#include <string.h>
#define maxOracionLargo 100

int analizarParentesis(char oracion[], int* parentesisIzqCount, int* parentesisDerCount)
{
    // si llego al final return
    if (oracion[0] == '\0') {
        printf("hay: %d '(' y %d ')', %s", *parentesisIzqCount, *parentesisDerCount, (*parentesisDerCount == *parentesisIzqCount ? "estan balanceados" : "no estan balanciados"));
        return 1;
    }

    // suma dependiendo de que parentesis encuentra
    //  el ++ tiene que esta por fuera de los parentesis, si no incremental el puntero y no el valor
    if (oracion[0] == '(') {
        (*parentesisIzqCount)++;
    } else if (oracion[0] == ')') {
        (*parentesisDerCount)++;
    }

    // se llama asi misma
    return analizarParentesis(&oracion[1], parentesisIzqCount, parentesisDerCount);
}

int main()
{

    char oracion[maxOracionLargo] = "(es decir, (si cada pa)réntesis ((izquierdo tiene su correspond))i)ente ho)";
    int parentesisIzq = 0, parentesisDer = 0;

    analizarParentesis(oracion, &parentesisIzq, &parentesisDer);
}