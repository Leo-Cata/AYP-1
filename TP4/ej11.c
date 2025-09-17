/*
Modificá el programa del ejercicio E8TP2 para que utilice dos funciones. Ambas deben recibir un arreglo de cadenas de caracteres que representen fechas y deben devolver la menor fecha del arreglo en un caso y la mayor en el otro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcion la cual toma una fecha y convierte sus partes a int, devolviendo la fecha en formato yyyymmdd para luego comparar
int stringDatesToInt(char* date)
{
    // variable para guardar temporalmente la fecha  y luego la pocia a esa variable
    char temporalString[11];
    strcpy(temporalString, date);

    // variable para almacenar la dir en memoria del resultado de strtok
    char* dividedStringToken = strtok(temporalString, "/");

    // variables para guarda las fechas
    //  atoi= ascii to int
    int day, month, year;
    day = atoi(dividedStringToken);

    dividedStringToken = strtok(NULL, "/");
    month = atoi(dividedStringToken);

    dividedStringToken = strtok(NULL, "/");
    year = atoi(dividedStringToken);

    return year * 10000 + month * 100 + day;
};

int findBiggestDate(char pointerDatesArray[][11])
{
    // variable para cual es resultado (ej 20241502 vs la siguiente fecha)
    // y variable para la posicion en donde se encuentra
    int result;
    int resultPos;

    for (int i = 0; i < 10; i++) {
        if (result < stringDatesToInt(pointerDatesArray[i])) {
            result = stringDatesToInt(pointerDatesArray[i]);
            resultPos = i;
        }
    }

    // devuelve la posicion de la fecha
    return resultPos;
}

int findSmallestDate(char pointerDatesArray[][11])
{
    // variable para cual es resultado (ej 20241502 vs la siguiente fecha)
    // y variable para la posicion en donde se encuentra
    int result;
    int resultPos;

    for (int i = 0; i < 10; i++) {
        if (result > stringDatesToInt(pointerDatesArray[i])) {
            result = stringDatesToInt(pointerDatesArray[i]);
            resultPos = i;
        }
    }

    // devuelve la posicion de la fecha
    return resultPos;
}
int main()
{
    char datesArray[10][11] = { "15/03/2020", "20/12/1999", "01/01/2023", "10/06/2018", "25/12/2022", "03/07/2021", "14/02/2017", "08/09/2024", "30/11/2015", "12/04/2016" };

    // biggestDate tiene que ser 0, la cual seria la fecha mas chica
    //  smallestDate tiene que ser 9999 99 99 para que sea la fecha mas grande posible
    int biggestDate;
    int smallestDate;

    // setea la fecha mas grande/chica el el num de la posicion en el array
    biggestDate = findBiggestDate(datesArray);
    smallestDate = findSmallestDate(datesArray);

    // luego las imprime
    printf("la fecha mas grande es: %s, y la fecha chica es: %s", datesArray[biggestDate], datesArray[smallestDate]);
};