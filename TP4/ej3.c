/*
#include <stdio.h>
int main()
{
    int x = 10;
    for (int x = 0; x < 5; x++) {
        printf("%d\n", x);
    }
    printf("%d\n", x);
    return 0;
}
el int x dentro del for loop es valido solamente para todo lo que este dentro de ese loop
por lo que imprime del 0 al 4
despues en el 2do print, imprime el int x que tiene alcance para todo main
*/

#include <stdio.h>
int main()
{
    int x = 10;
    {
        int x = 20;
        printf("%d\n", x);
    }
    printf("%d\n", x);
    return 0;
}

// el primer x tiene alcance para toda la funcion, pero como dentro de llaves hay otro x, ese tiene alcance para esas {}, imprime 20 y 10