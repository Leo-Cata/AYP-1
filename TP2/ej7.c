#include <stdio.h>
#define arrayLength 10
#define charMaxLength 10
/*
Escriba un programa que dado un arreglo de 10 cadenas de caracteres hardcoded lo imprima al
derecho (comenzando por la cadena de la primera posición) y al revés (comenzando por la última).
*/

int main()
{
    // variable hardcodeada pedida por la consigna
    char harcodedStrings[arrayLength][charMaxLength] = { "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez" };

    /*
    loopea por el array, cuando el valor no es el ultimo, osea "diez"
    agrega una , y espacio
    sino imprime (el ultimo valor) sin coma, y agrega un salto
    */
    printf("Array al derecho\n");
    for (int i = 0; i < arrayLength; i++) {
        if (i != arrayLength - 1) {
            printf("%s, ", harcodedStrings[i]);
        } else {
            printf("%s\n", harcodedStrings[i]);
        }
    }

    /*
    loopea por el array el revez, desde 10 a 0 inclusive
    cuando el valor de i es mayor a 0, imprime en la consola los valores espaciados con , y un espacio
    sino lo imprime solamente con un salto
    */
    printf("\nArray al revez\n");
    for (int i = 9; i >= 0; i--) {
        if (i > 0) {
            printf("%s, ", harcodedStrings[i]);
        } else if (i == 0) {
            printf("%s\n", harcodedStrings[i]);
        }
    }
}