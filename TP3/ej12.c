#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// definiciones para los numeros fijos
#define codeSize 10
#define nameSize 50
#define arraySize 100

// union para guardar un tipo u otro
union Stock {
    int unidades;
    float peso;
};

// catalogo de productos
struct Producto {
    char codigo[codeSize];
    char nombre[nameSize];
    int stockType; // 0 para unidades, 1 para kilos
    union Stock stock;
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

// funcion para agregar un producto
void addProduct(int* counter, struct Producto* catalogo)
{
    // limpia el buffer
    getchar();

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
    int newProductStockType;
    printf("para ingresar el stock, ingrese 1 para unidades, y 2 para el peso\n");
    scanf("%d", &newProductStockType);

    // inicializacion de las variables para los 2 tipos de stock
    // luego dependiendo si anteriormente se ingreso 0 para unidados
    // o 1 para peso (kilo/litros), se vuelva a preguntar para
    // ingresar un y guardar el respectivo stock
    int newProductStockUnits = 0;
    float newProductStockWeight = 0.0;

    // dependiendo del tipo de stock ingresado, pide un valor
    // si el tipo de stock ingresado es invalido, termina la funcion tirando error
    if (newProductStockType == 1) {
        printf("ingrese la cantidad de unidades enteras\n");
        scanf("%d", &newProductStockUnits);
    } else if (newProductStockType == 2) {
        printf("ingrese el peso como KG.GR O L.ML\n");
        scanf("%f", &newProductStockWeight);
    } else {
        printf("tipo de stock invalido\nla operacion se cancelara\n");
        return;
    }

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
        catalogo[*counter].precio = newProductPrice;
        catalogo[*counter].stockType = newProductStockType;

        // si el tipo de producto es 0/1, guarda el valor es su respectivo parametro
        if (newProductStockType == 1) {
            catalogo[*counter].stock.unidades = newProductStockUnits;
        } else if (newProductStockType == 2) {
            catalogo[*counter].stock.peso = newProductStockWeight;
        }
        printf("El producto se ha guardado\n");

        // aumenta para registrar cauntos productos hay en total
        (*counter)++;
    } else {
        printf("Se ha superado el numero maximo de productos\n");
    }
};

// funcion para buscar un producto por su nombre
void searchProduct(int* counter, struct Producto* catalogo)
{
    // limpia el buffer
    getchar();

    // logica para ingresar el nombre de un producto
    // asigarlo a una variable y agregar \0 para denotar que se termino la cadena
    char productNameToSearch[nameSize];
    printf("ingrese el nombre de un producto para buscarlo\n");
    fgets(productNameToSearch, sizeof(productNameToSearch), stdin);
    replaceWithArrayEnd(productNameToSearch);

    // for loop el cual busca desde el comienso hasta el ultimo valor del contador
    // un producto con el mismo nombre e imprime sus datos
    bool foundProduct = false;
    for (int i = 0; i < *counter && !foundProduct; i++) {
        // compara si el nombre del producto en posicion [i], es igual al producto ingresado
        // y luego lo imprime y setea la variable de encontrado
        if (strcmp(catalogo[i].nombre, productNameToSearch) == 0) {
            printf("Producto encontrado\ncodigo: %s, nombre: %s, precio: %.3f,  ",
                catalogo[i].codigo,
                catalogo[i].nombre,
                catalogo[i].precio);
            if (catalogo[i].stockType == 1) {
                printf("unidades: %d\n", catalogo[i].stock.unidades);
            } else {
                printf("peso: %.2fK/L", catalogo[i].stock.peso);
            }
            printf("\n");
            foundProduct = true;
        }
    }

    // si no hay resultados, imprime el error
    if (!foundProduct) {
        printf("el producto no fue encontrado\n");
    }
};

// funcion para imprimir todo el catalogo
void printCatalog(int* counter, struct Producto* catalogo)
{
    printf("productos:\n");
    // loopea desde 0 hasta el ultimo numero de productos registrado por el programa
    for (int i = 0; i < *counter; i++) {

        printf("codigo: %s, nombre: %s, precio: %.3f, ",
            catalogo[i].codigo,
            catalogo[i].nombre,
            catalogo[i].precio);
        // si el tipo de stock son unidades (1), o peso (2), imprime
        if (catalogo[i].stockType == 1) {
            printf("unidades: %d\n", catalogo[i].stock.unidades);
        } else {
            printf("peso: %.2f KG.GR/L.ML\n", catalogo[i].stock.peso);
        }
    }
}

int main()
{
    // array del struct
    struct Producto catalogo[arraySize];

    // contador de productos
    int counter = 0;

    // while loop para ejecutar todos los comandos o finalizar
    while (true) {

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
