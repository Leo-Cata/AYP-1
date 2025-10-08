/*
Escribí un programa que, utilizando una función recursiva, permita saber si una cadena de caracteres constituye un palíndromo
*/

#include <stdio.h>
#include <string.h>

// funcion recursiva para ver si es capicua
int esCapicua(char wordToCheck[], int wordLength)
{
    // si el largo es 1 o 0, retorna 1, osea es capicua
    if (wordLength == 1 || wordLength == 0) {
        return 1;
    }

    // si la palabra en la primera posicion y la ultima -1 (porque la ultima posicion seria \0) retorna 0, osea no es
    if (wordToCheck[0] != wordToCheck[wordLength - 1]) {
        return 0;
    }

    // llamado recurso, pasando la palabra con la posicion en mem del primer elemento, ya que se elimina el primero, y el largo -2 porque se descarto el primer elemento y el ultimo
    return esCapicua(&wordToCheck[1], wordLength - 2);
}

int main()
{
    char capicua[] = "hola";
    int wordLength = strlen(capicua);

    if (esCapicua(capicua, wordLength)) {
        printf("%s es capicua", capicua);
    } else {
        printf("%s no es capicua", capicua);
    }
}