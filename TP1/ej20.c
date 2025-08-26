#include <stdio.h>

int main() {
    int numberN, numberM;
    char operator;

    printf("ingrese numero, seguido de una operacion y luego otro numero \n");
    scanf("%i %c %i", &numberN, &operator, &numberM);

    switch (operator) {
    case '+':
        printf("el resultado de la suma es: %i \n", numberN + numberM);
        break;

    case '-':
        printf("el resultado de la resta es: %i \n", numberN - numberM);
        break;

    case '*':
        printf("el resultado de la multiplicacion es: %i \n", numberN * numberM);
        break;

    case '/':
        if (numberM != 0) {
            printf("el resultado de la division es: %i \n", numberN / numberM);
        } else {
            printf("operacion invalida");
        }
        break;

    default:
        break;
    }
}