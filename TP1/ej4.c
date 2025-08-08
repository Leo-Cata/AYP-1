#include <stdio.h>

int main(){
    int edad;
    printf("Escriba su edad\n");
    scanf("%i", &edad);

    if(edad >=18){
        printf("Eres mayor de edad\n");
    }else{
        printf("No eres mayor de edad\n");
    }
}