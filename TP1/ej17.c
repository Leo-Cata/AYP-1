#include <stdio.h>

int main(){
    /*
    hardcoded 2 primeros temrinos en variables, a y b
    se ingresa numero de cuantas veces se repite c
    loop imprimiendo a y a+b hasta que se llegue a c
    */

    int fibonacciRefA = 0;
    int fibonacciRefB = 1;
    int nextFibonacci;

    int numbCounter;

    printf("Ingrese un numero entero para mostrar x numeros de la serie de fibonacci \n");
    scanf("%i", &numbCounter);

    for(int i = 0; i < numbCounter; i++){
        printf("%i,\0 ", fibonacciRefA);

        //suma a con b para optener el sig numero (0+1,1+1,1+2,2+3,3+5)
        nextFibonacci= fibonacciRefA+ fibonacciRefB;

        //setea a como b
        fibonacciRefA = fibonacciRefB;

        //setea b como la suma de a y b
        fibonacciRefB= nextFibonacci;
    }
    
}