#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numberArray[10],randomNumb,isRepeated;

    srand(time(NULL));


    for(int i = 0; i< 20; i++){
        randomNumb= rand() % 10;
        printf("numeros random %i\n", randomNumb);

        for(int j = 0; j< 10; j++){
            if(isRepeated== 0){
                if(randomNumb == numberArray[j]){
                    isRepeated=1;   
                }
            }
        }
        
        if(isRepeated == 0){
            numberArray[i]=randomNumb;

        }else{
            isRepeated= 0;
            i--;
        }

        printf("array %i, \n", numberArray[i]);
    }

}