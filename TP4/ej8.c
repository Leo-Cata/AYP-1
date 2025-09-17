/*
Ejercicio 8. Modificá el programa del ejercicio E2TP1 para que use una función que reciba
el ingreso por teclado del usuario y devuelva un arreglo de caracteres que represente el nombre
1. char[] ingresarNombre();
2. char* ingresarNombre();
3. ingresarNombre(char *nombre);
4. ingresarNombre(char nombre[]);
*/

#include <stdio.h>
#define nameMaxLength 50

// funcion que pide el nombre y lo devuelve
void ingresarNombre(char* nombre)
{
    printf("cual es tu nombre?char*nombre[]\n");
    scanf("%s", nombre);
};

void ingresarNombre1(char nombre[])
{
    printf("cual es tu nombre? (char nombre[])\n");

    scanf("%s", nombre);
}

int main()
{
    // inicializacion de la variable e invocacion de la funcion
    char nombre[nameMaxLength];
    char nombre2[nameMaxLength];
    ingresarNombre(nombre);
    ingresarNombre1(nombre2);

    // imprime el saludo
    printf("hola: %s, hola2:%s", nombre, nombre2);
}

// 3 y 4 son correctos, 1 y 2 es sintaxis invalida
// char *nombre pasa la direccion de memoria del primer elemento
// char nombre[] hace lo mismo por lo que ambas son validas
