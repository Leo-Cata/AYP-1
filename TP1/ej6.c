#include <stdio.h>
//la diferencia es que con do while el codigo se va a ejecutar al menos una vez

int main(){
    int numero;
    int contador = 0;
    printf("Ingrese un numero\n");
    scanf("%i", &numero);

    do {
        printf("%i ", contador);
        contador= contador + 1;
        numero = numero - 1;
    }while(numero>=0);
}
