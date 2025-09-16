/*
Escribí un programa que reciba del usuario una fecha en formato dd/mm/aaaa (dos dígitos para el
día, dos para el mes y cuatro para el año) y almacene cada dato por separado en un registro. Al finalizar, debe
imprimir la fecha en formato dd-mm-aaaa.
*/
#include <stdio.h>
#define maxDia 31
#define maxMes 12
#define maxAno 9999
// struct de la fecha
struct Fecha {
    int dia;
    int mes;
    int ano;
};

int main()
{
    // inicializacion del struct y pide la fecha
    struct Fecha fechatInput;
    printf("Ingrese una fecha con formato dd/mm/aaaa\n");

    // si los datos de la fecha son mas grandes o chicos termina el programa
    // si no, imprime con formato dd-mm-aaaa
    scanf("%d/%d/%d", &fechatInput.dia, &fechatInput.mes, &fechatInput.ano);
    if (fechatInput.dia > maxDia || fechatInput.dia < 1 || fechatInput.mes > maxMes || fechatInput.mes < 1 || fechatInput.ano > maxAno || fechatInput.ano < 1) {
        printf("fecha invalida\n");
    } else {
        printf("%02d-%02d-%04d", fechatInput.dia, fechatInput.mes, fechatInput.ano);
    }
};