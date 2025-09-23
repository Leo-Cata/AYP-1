/*
Escribí un programa que al ejecutarse verifique si existe un archivo llamado “pidfile”.
Si el archivo existe, el programa debe finalizar con el mensaje
“El programa ya se encuentra en ejecución”. Si el archivo no existe,
debe crearlo, guardar el PID del programa y esperar a que el usuario ingrese cualquier tecla para luego borrar el archivo y finalizar
*/

#include <stdio.h>
// librearia para pid_t y getpid
#include <unistd.h>

#include <termios.h>

int main()
{
    // chequea si existe pidfile
    FILE* archivo = fopen("pidfile", "r");

    // si el archivo no existe, se crea
    if (archivo == NULL) {
        printf("el archivo no existe y se creara\n");
        archivo = fopen("pidfile", "w");

        // setea el id del proceso a la variable y chequea si existe
        pid_t pid = getpid();

        // escribe al archivo
        //&pid porque fwrite necesita la direccion de la memoria
        // para luego copiar los datos
        fwrite(&pid, sizeof(pid), 1, archivo);

        // y cierra el archivo
        fclose(archivo);

        printf("Presione enter para borrar el archivo ");

        getchar();

        remove("pidfile");
        return 0;

    } else {
        printf("El programa ya se encuentra en ejecución");
    }
}