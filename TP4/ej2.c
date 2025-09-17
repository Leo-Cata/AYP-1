/*#include <stdio.h>
void contador()
{
    static int count = 0;
    count++;
    printf("Contador: %d\n", count);
}
int main()
{
    contador();
    contador();
    contador();
    return 0;
}
en esta programa, la palabra static hace que le valor de count persiste a lo largo de la ejecucion
del programa en vez de que se reinicie con cada llamada
*/
/*
#include <stdio.h>
void contador()
{
    int count = 0;
    count++;
    printf("Contador: %d\n", count);
}
int main()
{
    contador();
    contador();
    contador();
    return 0;
}
como int no es static, cada vez que se llama al programa, se setea count = 0
*/

#include <stdio.h>
static int count = 0;
void contador()
{
    count++;
    printf("Contador: %d\n", count);
}
int main()
{
    contador();
    contador();
    contador();
    return 0;
}
// lo mismo que el primer programa, pero count es de alcance global, lo que hace que en todo el programa se pueda userla