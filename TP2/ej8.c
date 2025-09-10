#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Escriba un programa que a partir de un arreglo de 10 fechas (representadas como cadenas de
caracteres) hardcoded indique la mayor y la menor.
*/

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

int main()
{
    char datesArray[10][11] = { "15/03/2020", "20/12/199", "01/01/2023", "10/06/2018", "25/12/2022", "03/07/2021", "14/02/2017", "08/09/2024", "30/11/2015", "12/04/2016" };

    // biggerDate tiene que ser 0, la cual seria la fecha mas chica
    //  smallerdate tiene que ser 9999 99 99 para que sea la fecha mas grande posible
    int biggerDate = 0;
    int smallerDate = 99999999;

    // loopea por todas las partes del array
    //  si biggerdate mas grande es menor a lo que devuelve la guarda
    //  si smallerdate es mayor a lo que devuelva la funcion, la guarda
    for (int i = 0; i < 10; i++) {
        if (biggerDate < stringDatesToInt(datesArray[i])) {
            biggerDate = stringDatesToInt(datesArray[i]);
        }
        if (smallerDate > stringDatesToInt(datesArray[i])) {
            smallerDate = stringDatesToInt(datesArray[i]);
        }
    }

    printf("la fecha mas grande es: %d, y la fecha chica es: %d", biggerDate, smallerDate);
};
