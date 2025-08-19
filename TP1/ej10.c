#include <stdio.h>
/* Escriba un programa que permita ingresar un número natural N e 
imprima el factorial de N, es decir N! */
int main(){

    int numero;
    long int factorial = 1;

    printf("Ingrese un numero natural \n");
    scanf("%d", &numero);

    for (int i = 1; i < numero; i++)
    {
        factorial= factorial*(i+1);
    }
    
        printf("el factorial de %d, es: %ld \n", numero, factorial);
};