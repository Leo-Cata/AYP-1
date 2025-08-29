#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define randomArraySize 50
#define modaSize 10

/*
Escriba un programa que llene un arreglo con 50 números enteros aleatorios entre 0 y 10, 
y calcule e imprima la moda, la media y la desviación estándar.
*/
int main(){
    /*
    inicializacion de variables y creacion de la semilla random
    */ 
    int randomNumArray[randomArraySize],modaArray[modaSize], modaMaxValue=0, modaPosition=0,mediaSum=0;

    float mediaValue=0;

    srand(time(NULL));

    /*
    loopea 50 veces, guarda valores random del 0 al 10 en un array
    guarda en un array diferente la cantidad de veces que ese valor aparecio
    y suma el valor random para obtener la suma total de todos esos valores
    */
    for (int i = 0; i < randomArraySize; i++){
        //se asigna un numero random en cada loop
        int randomNum = rand() % 11;
        randomNumArray[i]=randomNum;
        modaArray[randomNum]++;
        mediaSum+= randomNum;
    }
    
    /*
    para cada elemento del 0 al 10 del array,
    si el valor de la posicion i es mayor al valor de la variable moda
    se guarda ese valor como un nuevo valor mas grande en la variable moda
    y guarda la posicion en la que se encuentra
    */
    for (int i = 0; i < modaSize; i++){
        if(modaArray[i]>modaMaxValue){
            modaMaxValue=modaArray[i];
            modaPosition=i;
        }
    }

    //imprime el valor de la moda y que numero es
    printf("la moda es: %d, para el numero: %d \n", modaMaxValue, modaPosition);

    //calcula el valor de la media y la imprime
    mediaValue= (float)mediaSum/50;
    printf("la media es: %g \n", mediaValue);
    
    
    {
        //calcula la suma de los cuadrados menos el valor de la media
        int sumaDeLosCuadrados=0;
        for (int i = 0; i < randomArraySize; i++){
            sumaDeLosCuadrados+=pow(randomNumArray[i]-mediaValue, 2);
        }

        //calcula la division de la suma de los cuadrados, por el numero total de valores -1
        float cuadradosDivididoTamaño=(float)sumaDeLosCuadrados/(randomArraySize-1);

        //calcula la raiz de cuadrados / tamaño -1
        float desviacion=sqrt(cuadradosDivididoTamaño);
        printf("la desviacion es:%g\n", desviacion);
    }
}