#include <stdio.h>

int main(){
    int numeroUno, numeroDos, resultado;

    printf("ingrese dos numeros natural para multiplicar\n");
    scanf("%i %i", &numeroUno, &numeroDos);

    for (int i = 0; i < numeroDos; i++){
        resultado = resultado + numeroUno;
    }

    printf("El resultado de la multiplicacion mediante suma es: %i\n", resultado);
}