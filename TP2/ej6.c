#include <stdio.h>

/*
Escriba dos programas que cumplan con la consigna del ejercicio 18, uno utilizando un arreglo de
enteros y otro una cadena de caracteres. ¿Cómo se define una cadena de caracteres en lenguaje C?
Implementar utilizando arreglo de enteros cargando cada valor individual y también implementar cargando
una cadena de caracteres char por char y agregar el ‘\0’
*/

int main()
{
    char charToCheck, reversedCharToCheck;
    int charLength = 0;

    printf("Ingrese una palabra para ver si es capicua\n");
    scanf("%i", &charToCheck);

        int temp_number = charToCheck;
    while (temp_number > 0) {
        int digit = temp_number % 10;

        reversedCharToCheck = reversedCharToCheck * 10 + digit;

        temp_number = temp_number / 10;
    }

    if (charToCheck == reversedCharToCheck) {
        printf("es capicua");
    } else {
        printf("No es capicua");
    }
}