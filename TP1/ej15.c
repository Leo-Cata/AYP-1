#include <stdio.h>

int main(){
    char letter;
    printf("ingrese una letra \0");
    scanf("%c", &letter);
    //desde A hasta Z
    if( letter >=65 && letter <=90){
        for (int i = 65; i < letter; i++){
            printf("%c \0", i);
        }
    };

    //desde a hasta z
    if(letter >=97 && letter <=122){
        for (int i = 97; i < letter; i++){
            printf("%c \0", i);
        }    
    }
}