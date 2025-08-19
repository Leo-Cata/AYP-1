#include <stdio.h>

int main(){

    int diaNacimiento, diaActual, mesNacimiento, mesActual, añoNacimiento, añoActual;

    printf("Ingrese su fecha de nacimiento (dd mm aaaa)\n");
    scanf("%d %d %d", &diaNacimiento, &mesNacimiento, &añoNacimiento);

    printf("Ingrese la fecha actual\n");
    scanf("%d %d %d", &diaActual, &mesActual, &añoActual);

    if(mesNacimiento > mesActual && diaNacimiento > diaActual){
        printf("Su edad es %d\n", añoActual-añoNacimiento-1);
    }else{
        printf("Su edad es %d\n", añoActual-añoNacimiento);
    }
};