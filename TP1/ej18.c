#include <stdio.h>

int main(){
    int numberToCheck, reversedNumberToCheck;

    printf("Ingrese un numero para ver si es capicua\n");
    scanf("%i", &numberToCheck);

    int temp_number= numberToCheck;
    while(temp_number > 0){
        int digit = temp_number % 10;

        reversedNumberToCheck= reversedNumberToCheck * 10 + digit;

        temp_number= temp_number/10;
    }

    if(numberToCheck == reversedNumberToCheck){
        printf("es capicua");
    }else{
        printf("No es capicua");
    }
}