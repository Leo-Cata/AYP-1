/*
Escribí un programa que lea el archivo “datosImportados.dat” del ejercicio anterior y permita:
A. Listar todos los registros numerados consecutivamente.
B. Buscar y mostrar un registro por su número de orden.
C. Eliminar un registro por su número de orden.
D. Modificar un registro indicando su número de orden
*/

#include <stdio.h>
#include <string.h>
#define maxLengthNames 50
#define maxStructLength 50
#define DNILength 9

// estructura
struct Fecha {
    int dia;
    int mes;
    int anio;
};
struct Persona {
    char nombre[maxLengthNames];
    char apellido[maxLengthNames];
    struct Fecha fechaNacimiento;
    int edad;
    char dni[DNILength];
};

// funcion que lista todos los elementos
void listAllRegisters(struct Persona* punteroPersonas, int personasLeidas)
{
    // loopea por todo el array e imprime cada uno
    for (int i = 0; i < personasLeidas; i++) {
        printf("%d) Nombre: %s, Apellido: %s, Fecha de nacimiento: %02d/%02d/%04d, Edad: %d y DNI: %s\n",
            i,
            punteroPersonas[i].nombre,
            punteroPersonas[i].apellido,
            punteroPersonas[i].fechaNacimiento.dia,
            punteroPersonas[i].fechaNacimiento.mes,
            punteroPersonas[i].fechaNacimiento.anio,
            punteroPersonas[i].edad,
            punteroPersonas[i].dni);
    }
}

// funcion la cual pide un numero de dni y busca el elemento para imprimirlo
int findDNI(struct Persona* punteroPersonas, int personasLeidas)
{
    // variable para guardar que numero en el registro se va a buscar
    char DNItoFind[DNILength];
    printf("Ingrese un DNI para buscar \n");
    scanf("%s", &DNItoFind);

    // itera por todos los elementos, se hay un match lo imprime y termina
    for (int i = 0; i < personasLeidas; i++) {
        if (strcmp(DNItoFind, punteroPersonas[i].dni) == 0) {

            printf("%d) Nombre: %s, apellido: %s, fecha de nacimiento: %02d/%02d/%04d, edad: %d y DNI: %s\n",
                i,
                punteroPersonas[i].nombre,
                punteroPersonas[i].apellido,
                punteroPersonas[i].fechaNacimiento.dia,
                punteroPersonas[i].fechaNacimiento.mes,
                punteroPersonas[i].fechaNacimiento.anio,
                punteroPersonas[i].edad,
                punteroPersonas[i].dni);
            return 0;
        }
    }

    // se ejecuta cuando no se encontraron matches
    printf("No hay resultados");
}

// funcion la cual borra un elemento del struct y copia esos datos al archivo
int deleteDNI(struct Persona* punteroPersonas, int* personasLeidas)
{

    // variable para saber que numero de DNI ingreso el usuario
    char DNIToDelete[DNILength];
    printf("Ingrese un DNI para borrar\n");
    scanf("%s", DNIToDelete);

    // variable para guardar en que posicion se encontro el dni
    int positionInRegister = -1;

    for (int i = 0; i < *personasLeidas; i++) {
        if (strcmp(DNIToDelete, punteroPersonas[i].dni) == 0) {
            positionInRegister = i;
            break;
        }
    }

    // si no hay resultados muestra un error
    if (positionInRegister == -1) {
        printf("No hay resultados");
        return 1;
    }

    // busca el archivo para escribirlo en binario (borra todo al hacer wb)
    FILE* archivo = fopen("datosImportados2.dat", "wb");
    if (archivo == NULL) {
        printf("hubo un error");
        return 1;
    }

    // desde el numero que ingreso el usuario setea el siguiente valor a ese
    // moviendo todos los elementos 1 hacia atras desde el numero que ingreso el usuario
    for (int i = positionInRegister; i < *personasLeidas; i++) {
        punteroPersonas[i] = punteroPersonas[i + 1];
    }

    // resta la cantidad de personas leidas
    (*personasLeidas)--;

    // escribe la nueva info y cierra el archivo
    fwrite(punteroPersonas, sizeof(struct Persona), *personasLeidas, archivo);
    fclose(archivo);

    // e indica que se realizo la operacion
    printf("Se ha borrado el registro %d\n", positionInRegister);
}
// fucion la cual pregunta por un numero, muestra la info y la edita
int editByNumber(struct Persona* punteroPersonas, int personasLeidas)
{
    // variable para pedir que numero se quiere editar
    int registerNumberToEdit;
    printf("Seleccione un numero del 0 al %d para editar\n", personasLeidas - 1);
    scanf("%d", &registerNumberToEdit);

    // lo muestra y luego pide la nueva info
    printf("%d) Nombre: %s, Apellido: %s, Fecha de nacimiento: %02d/%02d/%04d, Edad: %d y DNI: %s\n",
        registerNumberToEdit,
        punteroPersonas[registerNumberToEdit].nombre,
        punteroPersonas[registerNumberToEdit].apellido,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.dia,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.mes,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.anio,
        punteroPersonas[registerNumberToEdit].edad,
        punteroPersonas[registerNumberToEdit].dni);

    printf("Ingrese nuevo NOMBRE APELLIDO FECHA(DD/MM/AAAA) y EDAD\n");
    scanf("%s %s %02d/%02d/%04d %d",
        punteroPersonas[registerNumberToEdit].nombre,
        punteroPersonas[registerNumberToEdit].apellido,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.dia,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.mes,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.anio,
        &punteroPersonas[registerNumberToEdit].edad,
        punteroPersonas[registerNumberToEdit].dni);

    // abre el archivo, escribe la nueva info y lo cierra
    FILE* archivo = fopen("datosImportados2.dat", "wb");
    if (archivo == NULL) {
        printf("hubo un error");
        return 1;
    }

    fwrite(punteroPersonas, sizeof(struct Persona), personasLeidas, archivo);
    fclose(archivo);

    // e indica que se realizo la operacion
    printf("Se han guardado los cambias");
}

int main()
{
    // variable para elegir la operacion
    int menuOperation;

    // carga el archivo
    FILE* archivo = fopen("datosImportados2.dat", "rb");
    if (archivo == NULL) {
        printf("Archivo no encontrado");
        return 1;
    }

    // struct para guardar todos los datos
    struct Persona personas[maxStructLength];

    // registra cuantos datos hay en el archivo y lo cierra
    int personasLeidas = fread(&personas, sizeof(struct Persona), maxStructLength, archivo);
    fclose(archivo);

    // instrucciones para correr el programa
    printf("ingrese un numero de acuerdo a la operacion\n1. mostrar todo el registro\n2. buscar y mostrar\n3. borrar un elemento\n4. editar un elemento\n");
    scanf("%d", &menuOperation);

    // switch para seleccionar la operacion
    switch (menuOperation) {
    case 1:
        listAllRegisters(personas, personasLeidas);
        break;
    case 2:
        findDNI(personas, personasLeidas);
        break;
    case 3:
        deleteDNI(personas, &personasLeidas);
        break;
    case 4:
        editByNumber(personas, personasLeidas);
        break;

    default:
        break;
    }
}