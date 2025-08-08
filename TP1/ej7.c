#include <stdio.h>
//la diferencia es que con for se realizan loops

int main(){
    int numero;
    int contador = 0;
    printf("Ingrese un numero\n");
    scanf("%i", &numero);

    for (int i = 0; i <= numero; i++)
    {
        printf("%i ", contador);
        contador= contador + 1;
    }
}