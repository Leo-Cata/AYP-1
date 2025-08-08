#include <stdio.h>

int main(){
    int numero;
    int contador = 0;
    printf("Ingrese un numero\n");
    scanf("%i", &numero);

    while(numero>=0){
        printf("%i ", contador);
        contador= contador + 1;
        numero = numero - 1;
    }
}