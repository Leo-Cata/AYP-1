#include <stdio.h>
#include <string.h>

// definiciones para los numeros fijos
#define codeSize 10
#define nameSize 50
#define arraySize 100

// catalogo de productos
struct Producto {
    char codigo[codeSize];
    char nombre[nameSize];
    int stock;
    float precio;
};

// toma un array de caracetres, si no es nulo
// busca en que posicion del array se encuentra el primero \n y lo reemplaza con \0
// para indicar que se termino el array
void replaceWithArrayEnd(char* array)
{
    if (array != NULL) {
        array[strcspn(array, "\n")] = '\0';
    }
}

void cleanBuffer()
{
    while (getchar() != '\n')
        ;
}

// funcion para agregar un producto
void addProduct(int* counter, struct Producto* catalogo)
{
    // limpia el buffer
    cleanBuffer();

    // logica para ingresar el codigo de un nuevo producto, asignarlo y reemplazar el salto por finalizacion de la cadena
    char newProductCode[codeSize];
    printf("ingrese un codigo de hasta 10 caracteres para registrar\n");
    fgets(newProductCode, sizeof(newProductCode), stdin);
    replaceWithArrayEnd(newProductCode);

    // logica para ingresar el nombre de un nuevo producto, asignarlo y reemplazar el salto por finalizacion de la cadena
    char newProductName[nameSize];
    printf("ingrese un nombre de hasta 50 caracteres para registrar\n");
    fgets(newProductName, sizeof(newProductName), stdin);
    replaceWithArrayEnd(newProductName);

    // logica para ingresar el stock de un nuevo producto, asignarlo
    int newProductStock = 0;
    printf("ingrese el stock registrar\n");
    scanf("%i", &newProductStock);

    // logica para ingresar el precio de un nuevo producto, asignarlo
    float newProductPrice = 0.0;
    printf("ingrese un precio\n");
    scanf("%f", &newProductPrice);

    // si el contador es menor que el tamaño maximo,
    // copia los datos ingresados por el usuario para registrar un nuevo producto
    // suma al contador 1 para saber cual es la ultima posicion
    if (*counter < arraySize) {
        strcpy(catalogo[*counter].codigo, newProductCode);
        strcpy(catalogo[*counter].nombre, newProductName);
        catalogo[*counter].stock = newProductStock;
        catalogo[*counter].precio = newProductPrice;
        (*counter)++;
    } else {
        printf("Se ha superado el numero maximo de productos\n");
    }
};

// funcion para buscar un producto por su nombre
void searchProduct(int* counter, struct Producto* catalogo)
{
    // limpia el buffer
    cleanBuffer();

    // logica para ingresar el nombre de un producto
    // asigarlo a una variable y agregar \0 para denotar que se termino la cadena
    char productNameToSearch[nameSize];
    printf("ingrese el nombre de un producto para buscarlo\n");
    fgets(productNameToSearch, sizeof(productNameToSearch), stdin);
    replaceWithArrayEnd(productNameToSearch);

    // for loop el cual busca desde el comienso hasta el ultimo valor del contador
    // un producto con el mismo nombre e imprime sus datos
    int foundProduct = 0;
    for (int i = 0; i < *counter; i++) {
        // compara si el nombre del producto en posicion [i], es igual al producto ingresado
        // y luego lo imprime y setea la variable de encontrado
        if (strcmp(catalogo[i].nombre, productNameToSearch) == 0) {
            printf("Producto encontrado: %s %s %d %.3f\n",
                catalogo[i].codigo,
                catalogo[i].nombre,
                catalogo[i].stock,
                catalogo[i].precio);
            printf("\n");
            foundProduct = 1;
            break;
        }
    }

    // si no hay resultados, imprime el error
    if (foundProduct == 0) {
        printf("el producto no fue encontrado\n");
    }
};

// funcion para imprimir todo el catalogo
void printCatalog(int* counter, struct Producto* catalogo)
{
    // loopea desde 0 hasta el ultimo numero de productos registrado por el programa
    for (int i = 0; i < *counter; i++) {

        printf("Productos: %s %s %d %.3f\n",
            catalogo[i].codigo,
            catalogo[i].nombre,
            catalogo[i].stock,
            catalogo[i].precio);
    }
}

int main()
{
    // array del struct
    struct Producto catalogo[arraySize];

    // contador de productos
    int counter = 0;

    // while loop para ejecutar todos los comandos o finalizar
    while (1) {

        // inicializacion de variables para saber que desea el usuario hacer
        // y contador para el array de productos
        int operation = 0;

        // instrucciones para el usuario
        printf("Ingrese un numero segun la operacion que desea realizar\n");
        printf("1. agregar un producto nuevo\n");
        printf("2. buscar un producto por su nombre\n");
        printf("3. mostrar todo el catalogo\n");
        printf("4. salir\n");

        // lectura de la operacion
        scanf("%d", &operation);

        // logica para terminar el programa
        if (operation == 4) {
            printf("cerrando el programa...");
            break;
        }

        // switch case, en el cual dependiendo del numero
        switch (operation) {
        case 1:
            addProduct(&counter, catalogo);
            break;

        case 2:
            searchProduct(&counter, catalogo);
            break;

        case 3:
            printCatalog(&counter, catalogo);
            break;

        default:
            break;
        }
    }
}
