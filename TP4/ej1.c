#include <stdio.h>

int x = 10;
void funcion(int x)
{
    printf("%d\n", x);
}
int main()
{
    funcion(20);
    printf("%d\n", x);
    return 0;
}

// deberia imprimir 20 y despues 10
// porque le pasa el numero 20 a funcion, y el otro print imprime la variable X