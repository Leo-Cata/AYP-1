/*
Escribí un programa que lea el contenido de su archivo fuente (.c) y lo imprima por pantalla
*/

#include <stdio.h>
#define charLength 256

int main()
{
    char archivoText[charLength];
    // crea el pointer al archivo y lo abre
    FILE* archivo = fopen("ej1.c", "r");

    // si no se pudo leer termina el programa
    if (archivo == NULL) {
        printf("No se puedo leer");
        return 1;
    }

    // size_t unsigned long, representa tamaño en bytes de lo que se leyo
    // size_t bytesLeidos;

    // // cuando bytesLeidos es mayor a eso ejecuta el while
    // while ((bytesLeidos = fread(archivoText, 1, charLength - 1, archivo)) > 0) {
    //     // setea la ultima posicion como fin de linea para que no hayan problemas
    //     archivoText[bytesLeidos] = '\0';

    //     // imprime el texto
    //     printf(" %s", archivoText);
    // }

    // fgets lee de a solo 1 linea, fread lee la cantidad dada por charLength-1
    while (fgets(archivoText, charLength, archivo) != NULL) {
        printf("%s", archivoText);
    }

    fclose(archivo);
    return 0;
}