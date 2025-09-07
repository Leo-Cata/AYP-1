#include <stdio.h>

// funciones para cada tipo de operacion con enteros
//  dando como return, el resultado
int sum(int num1, int numb2)
{
    return num1 + numb2;
}

int subtraction(int num1, int numb2)
{
    return num1 - numb2;
}

int multiplication(int num1, int numb2)
{
    return num1 * numb2;
}

int divide(int num1, int numb2)
{
    return num1 / numb2;
}

// funcion principal
int main()
{
    int numberN, numberM;
    char operator;

    printf("ingrese numero, seguido de una operacion y luego otro numero \n");
    scanf("%i %c %i", &numberN, &operator, &numberM);

    // switch case que realiza la operacion con los numeros ingresados en el printf anterior
    switch (operator) {
    case '+':
        printf("el resultado de la suma es: %i \n", sum(numberN, numberM));
        break;

    case '-':
        printf("el resultado de la resta es: %i \n", subtraction(numberN, numberM));
        break;

    case '*':
        printf("el resultado de la multiplicacion es: %i \n", multiplication(numberN, numberM));
        break;

    case '/':
        if (numberM != 0) {
            printf("el resultado de la division es: %i \n", divide(numberN, numberM));
        } else {
            printf("operacion invalida");
        }
        break;
    default:
        break;
    }
}