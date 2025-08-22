#include <stdio.h>

int main(){
    char letter;

    printf("Ingrese una letra \n");
    scanf("%c", &letter);
//1er loop, desde Z hasta A
//2do loop, desde z hasta a
    if(letter >= 65 && letter <=90){
        for (int i = 90; i > letter; i--){
            printf("%c \0", i);
        }
    }else if(letter >= 97 && letter <= 122){
        for (int i = 122; i > letter; i--){
            printf("%c \0", i);
        }
        
    }
}