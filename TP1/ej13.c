#include <stdio.h>
/*
Escriba un programa que permita ingresar un número natural N y otro número natural M
, e imprima el resultado de N elevado a la M calculándolo como suma sucesivas
*/
int main(){

    int numeroN, numeroM, resultado=1;
    printf("ingrese dos numeros naturales para elevar uno por el otro\n");
    scanf("%i %i", &numeroN, &numeroM);

    for (int i = 0; i < numeroM; i++)
    {
        resultado = resultado*numeroN;
    }
    
    printf("El resultado es: %i", resultado);
}