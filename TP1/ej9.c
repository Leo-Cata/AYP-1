#include <stdio.h>

int main(){
    int dia, mes;
    printf("Ingrese su fecha de nacimiento (dd mm aa)\n");
    scanf("%d %d", &dia, &mes);
    printf("Dia: %d, Mes: %d \n", dia, mes);

    if(mes >= 3 && mes<=6){
        if (mes == 3 && dia>20){
            printf("Naciste en Otoño\n");
        }else if (mes == 6 && dia > 20){
            printf("Naciste en Invierno\n");
        };
    };

    if (mes > 6 && mes <= 9){
        if(mes == 9 && dia >20){
            printf("Naciste en Primavera\n");
        }else{
            printf("Naciste en Invierno\n");
        };
    };

    if(mes > 9 && mes <= 12){
        if(mes == 12 && dia > 20){
            printf("Naciste en Verano\n");
        }else{
            printf("Naciste en Primavera\n");
        }
    };
}
