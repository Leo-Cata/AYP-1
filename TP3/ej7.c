/*
El siguiente programa descompone un número entero como producto de números primos
indicá cómo lo modificarías para utilizar subrutinas
respetando buenas prácticas como el principio de máxima localidad
*/
#include <stdio.h>

// funcion que imprime los numeros primos
void printPrimes(int inputNumber)
{
    // Iteramos desde 2 (el primer número primo) hasta n
    for (int i = 2; i <= inputNumber; i++) {
        while (inputNumber % i == 0) {
            // Si n es divisible por i, i es un factor primo
            printf("%d", i);
            inputNumber = inputNumber / i;
            // Si aún quedan más primos, imprimimos un asterisco
            if (inputNumber > 1) {
                printf(" * ");
            }
        }
    }
    printf("\n");
};

int main()
{
    // variable inicializada en 0, la cual el usuario entra un numero
    int inputNumber = 0;
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &inputNumber);

    // si el numero ingresado es incorrecto lo undica
    if (inputNumber <= 1) {
        printf("El número debe ser mayor que 1.\n");
        return 1;
    }

    // imprime el numero ingresado y los factores que dividen a ese numero
    printf("Los factores primos de %d son: ", inputNumber);
    printPrimes(inputNumber);

    // termina el programa
    return 0;
}