/*
Ejercicio 8. Modificá el programa del ejercicio E2TP1 para que use una función que reciba el ingreso por teclado del usuario y devuelva un arreglo de caracteres que represente el nombre
*/

#include <stdio.h>
#define nameMaxLength 50

// funcion que pide el nombre y lo devuelve
void ingresarNombre(char* nombre)
{
    printf("cual es tu nombre?\n");
    scanf("%s", nombre);
};

int main()
{
    // inicializacion de la variable e invocacion de la funcion
    char nombre[nameMaxLength];
    ingresarNombre(nombre);

    // imprime el saludo
    printf("hola: %s", nombre);
}
