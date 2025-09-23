/*
Escribí un programa que lea un archivo llamado “datosAImportar.dat” con el siguiente formato:
nombre;apellido;fechaNacimiento;edad;dni
Utilizando lo realizado en el ejercicio 10 del práctico 3, transformá cada línea de este archivo en un registro de tipo Persona y luego escribí todos los registros en un archivo que se llame “datosImportados.dat”.
*/

#include <stdio.h>
#include <time.h>
#define maxLengthNames 50
#define DNILength 8

// estructuras dadas por el ejercicio
struct Fecha {
    int dia;
    int mes;
    int anio;
};
struct Persona {
    char nombre[maxLengthNames];
    char apellido[maxLengthNames];
    struct Fecha fechaNacimiento;
    int edad;
    char dni[DNILength]; // agregado para el ej7
};

// funcion para guardar los datos que estan en el struct, al archivo datosImportados.dat
int guardarDatos(struct Persona* punteroPersonaDatos)
{

    // guarda estos datos en DatosImportados.dat
    FILE* archivo = fopen("DatosImportados2.dat", "ab");

    if (archivo == NULL) {
        printf("archivo no encontrado\n");
        return 1;
    }

    // escribe los datos de personas al archivo, 1 a la vez
    fwrite(punteroPersonaDatos, sizeof(struct Persona), 1, archivo);

    // y cierra el archivo
    fclose(archivo);
};

// funcion que imprime todos los datos
void imprimirDatos(struct Persona personaDatos)
{
    printf("La persona %s %s nació el día %02d-%02d-%04d y tiene %d años de edad con DNI: %s\n",
        personaDatos.nombre,
        personaDatos.apellido,
        personaDatos.fechaNacimiento.dia,
        personaDatos.fechaNacimiento.mes,
        personaDatos.fechaNacimiento.anio,
        personaDatos.edad,
        personaDatos.dni);
};

// funcion para calcular la edad
void calcularEdad(struct Persona* punteroPersonaDatos)
{

    // variable de timeo time
    time_t timeRaw;

    // guarda el tiempo en &variable
    time(&timeRaw);

    // struct de formato tm(fecha)
    struct tm* formatedTime;

    // combierte todos los datos y los guarda
    formatedTime = localtime(&timeRaw);

    // si el dia y la fecha de nacimiento es mayor a la fecha actual, calcula la edad correcta restandole 1 al anio
    if (punteroPersonaDatos->fechaNacimiento.dia > formatedTime->tm_mday && punteroPersonaDatos->fechaNacimiento.mes >= formatedTime->tm_mon) {

        // calcula la edad mediante anio actual (anios desde 1900 en la fecha actual + 1900 menos fecha de nacimiento menos 1)
        punteroPersonaDatos->edad = (1900 + formatedTime->tm_year) - punteroPersonaDatos->fechaNacimiento.anio - 1;
    } else {

        // calcula la edad mediante anio actual (anios desde 1900 en la fecha actual + 1900 menos fecha de nacimiento)
        punteroPersonaDatos->edad = (1900 + formatedTime->tm_year) - punteroPersonaDatos->fechaNacimiento.anio;
    }
};

int main()
{

    struct Persona personaDatos;

    FILE* archivo = fopen("datosAImportar2.dat", "r");
    if (archivo == NULL) {
        printf("Archivo no encontrado");
        return 1;
    }

    // mientras que lo escaneado en el archivo sean 6 campos
    // setea la informacion al struct
    while (fscanf(archivo, "%[^;];%[^;];%d/%d/%d;%d;%s\n",
               personaDatos.nombre,
               personaDatos.apellido,
               &personaDatos.fechaNacimiento.dia,
               &personaDatos.fechaNacimiento.mes,
               &personaDatos.fechaNacimiento.anio,
               &personaDatos.edad,
               personaDatos.dni)
        == 7) {

        // lee 1 caracter, seguido de lo que leyo, si no es un salto de linea y no es el end of file, lo devuelve
        // esto permite que el archivo este separado tanto por saltos de lineas como ; entre cada persona
        int saltoDeLineaEnArchivo = fgetc(archivo);
        if (saltoDeLineaEnArchivo != '\n' && saltoDeLineaEnArchivo != EOF) {
            ungetc(saltoDeLineaEnArchivo, archivo);
        }

        // si se ha llegado al final del archivo (file end of life)
        // cierra el archivo y termina el programa
        if (feof(archivo)) {
            fclose(archivo);
            return 1;
        }
        // guarda los datos
        guardarDatos(&personaDatos);

        // calcula la edad
        calcularEdad(&personaDatos);

        // funcion para imprimir todos los datos
        // no necesita un puntero, osea el struct original memoria ya que no es necesario modificar nada
        // por lo tanto si se recibe una copia o no, realiza lo que se le pide a la funcion
        imprimirDatos(personaDatos);
    }
}