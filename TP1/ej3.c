#include <stdio.h>

int main(){
    int año;

    printf("Escriba su año de nacimiento\n");
    scanf("%i", &año);
    int edad = 2025-año;
    printf("Tu edad aproximada es: %i años\n", edad);
}