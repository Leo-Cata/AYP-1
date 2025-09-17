/*
realizá un programa que reciba del usuario nombre, apellido y fecha de nacimiento (dd/mm/aaaa), calcule la edad y guarde todos los datos en un registro. Luego debe imprimir todos los datos en una sola cadena con el siguiente formato: “La persona nombre apellido nació el día dd-mm-aaaa y tiene n años de edad”. Utilizá al menos una función para completar la estructura, otra para calcular la edad (obteniendo la fecha actual con lo realizado en el ejercicio anterior) y otra para imprimir por pantalla la cadena
*/

#include <stdio.h>
#include <time.h>
#define maxLengthNames 50

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
};

// funcion que guarda los datos en el struct, tomando un puntero al struct de datos de personas
void guardarDatos(struct Persona* punteroPersonaDatos)
{
    // escanea, tomando el nombre, apellido, y luego la fecha de nacimiento
    // delimitada por "/"
    scanf("%s %s %d/%d/%d",
        &punteroPersonaDatos->nombre,
        &punteroPersonaDatos->apellido,
        &punteroPersonaDatos->fechaNacimiento.dia,
        &punteroPersonaDatos->fechaNacimiento.mes,
        &punteroPersonaDatos->fechaNacimiento.anio);
};

// funcion que imprime todos los datos
void imprimirDatos(struct Persona personaDatos)
{
    printf("La persona %s %s nació el día %02d-%02d-%04d y tiene %d años de edad",
        personaDatos.nombre,
        personaDatos.apellido,
        personaDatos.fechaNacimiento.dia,
        personaDatos.fechaNacimiento.mes,
        personaDatos.fechaNacimiento.anio,
        personaDatos.edad);
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

    printf("Ingrese NOMBRE APELLIDO y fecha de nacimiento (DD/MM/AAAA)\n");

    // guarda los datos
    guardarDatos(&personaDatos);

    // calcula la edad
    calcularEdad(&personaDatos);

    // funcion para imprimir todos los datos
    // no necesita un puntero, osea el struct original memoria ya que no es necesario modificar nada
    // por lo tanto si se recibe una copia o no, realiza lo que se le pide a la funcion
    imprimirDatos(personaDatos);
}