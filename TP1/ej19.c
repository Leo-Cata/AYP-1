#include <stdio.h>

int main(){
    int count,number;

    printf("ingrese un numero entero para contar sus digitos \n");
    scanf("%d", &number);

    if(number>0){
        while(number>0){
            number /=10;
            count++;
        }
    }else{
        printf("Contiene 0 digitos \0");
    }

    printf("el numero ingresado contien: %d digitos", count++);
}