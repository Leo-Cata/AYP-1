/*
Modifica el ejercicio anterior, para presentar en pantalla el valor de ‘p’, y las direcciónes de
memoria de: ‘a’, ‘a[0]’, ‘a[1]’, ‘a[2]’, ‘a[3]’, ‘a[4]’. ¿qué conclusión puedes hacer al respecto del resultado?
*/
#include <stdio.h>

int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int* p = &a[0];

    printf("valor de p: %d, direccion de memoria: %p\n", *p, p);
    printf("valor de p: %d, direccion de memoria: %p\n", *p + 1, p + 1);
    printf("valor de p: %d, direccion de memoria: %p\n", *p + 2, p + 2);
    printf("valor de p: %d, direccion de memoria: %p\n", *p + 3, p + 3);
    printf("valor de p: %d, direccion de memoria: %p\n", *p + 4, p + 4);
}

// la conclusion es que unu array son simplemente lugares en memoria continuo y mediante variables se puede ingresar a ellas mismas