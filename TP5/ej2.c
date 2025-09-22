/*
Escribí un programa que lea el contenido de un archivo indicado en la línea de comandos al ejecutarlo y lo imprima por pantalla
*/

#include <stdio.h>
#define charLength 256

int main(int argumentoCount, char* argumentoArchivoNombrePorLinea[])
{
    char archivoText[charLength];

    // lee un archivo dado
    // argumentoArchivoNombrePorLinea[0]= ./ej2
    // argumentoArchivoNombrePorLinea[1]= nombreDelArchivo.c

    FILE* archivo = fopen(argumentoArchivoNombrePorLinea[1], "r");

    // si el archivo existe y la cantidad de argumentos es menor a 1
    // termina
    if (archivo == NULL || argumentoCount < 1) {
        printf("No se puedo leer");
        return 1;
    }

    // mientras el fgets no sea invalido, lee todo lo que hay
    // linea por linea en el archivo pasado
    while (fgets(archivoText, charLength, archivo) != NULL) {
        printf("%s", archivoText);
    }

    fclose(archivo);
}