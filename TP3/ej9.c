/*
Utilizando las funciones presentes en time.h obtené el día actual
e imprimilo por pantalla con el formato “Hoy es dd/mm/yyyy”
*/

#include <stdio.h>
#include <time.h>

int main()
{
    // variable para guardar el tiempo (en formato segundos desde unix 1 1/01/1900)
    time_t timeInSec;

    // funcion que guarda el tiempo actual en el puntero
    time(&timeInSec);

    // struct pre-escrita por C con los formatos de tiempos
    struct tm* formatedTime;

    // setea el tiempo actual en la estructura (el struct tiene que ser un puntero)
    formatedTime = localtime(&timeInSec);

    // tm_year contiene la cantidad de anos desde 1900, por lo tanto hay que agregarle 1900
    printf("hoy es: %02d/%02d/%d", formatedTime->tm_mday, formatedTime->tm_mon, formatedTime->tm_year + 1900);
}