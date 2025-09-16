/*
Modificá el programa del ejercicio E8TP1 para implementar el cálculo de la edad exacta mediante una función, como alguna de las siguientes:
int calcularEdad(char[] fechaNacimiento);
int calcularEdad(int diaNac, int mesNac, int anioNac);
*/
#include <stdio.h>

// funcion para calcular la edad actual
// toma los valores, y si el mes nacimiento es mayor o igual al actual, y el dia actual es mayor al de nacimiento, calcula la edad restandole 1
int calcularEdad(int diaNacimiento, int diaActual, int mesNacimiento, int mesActual, int añoActual, int añoNacimiento)
{
    if (mesNacimiento >= mesActual && diaNacimiento > diaActual) {
        return añoActual - añoNacimiento - 1;
    } else {
        return añoActual - añoNacimiento;
    }
};

int main()
{

    // inicializacion de las variables
    int diaNacimiento, diaActual, mesNacimiento, mesActual, añoNacimiento, añoActual, edadCalculada;

    // le pide la fecha de nacimiento con un formato especifico
    printf("Ingrese su fecha de nacimiento (dd mm aaaa)\n");
    scanf("%d %d %d", &diaNacimiento, &mesNacimiento, &añoNacimiento);

    // y la fecha actual
    printf("Ingrese la fecha actual\n");
    scanf("%d %d %d", &diaActual, &mesActual, &añoActual);

    // setea la edad calculada mediante la invocacion de una funcion
    edadCalculada = calcularEdad(diaNacimiento, diaActual, mesNacimiento, mesActual, añoActual, añoNacimiento);

    // y la imprime
    printf("la edad es: %d", edadCalculada);
};