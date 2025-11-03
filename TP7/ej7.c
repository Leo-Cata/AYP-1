/*
Modificá el programa del ejercicio 6 del práctico 5 para agregar una opción que ordene los
registros por número de DNI utilizando quicksor
*/

#include <stdio.h>
#define maxLengthNames 50
#define maxStructLength 50

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
};

// funcion que lista todos los elementos
void listAllRegisters(struct Persona* punteroPersonas, int personasLeidas)
{
    // loopea por todo el array e imprime cada uno
    for (int i = 0; i < personasLeidas; i++) {
        printf("%d) Nombre: %s, Apellido: %s, Fecha de nacimiento: %d/%d/%d, Edad: %d\n",
            i,
            punteroPersonas[i].nombre,
            punteroPersonas[i].apellido,
            punteroPersonas[i].fechaNacimiento.dia,
            punteroPersonas[i].fechaNacimiento.mes,
            punteroPersonas[i].fechaNacimiento.anio,
            punteroPersonas[i].edad);
    }
}

// funcion la cual pide un numero y busca el elemento para imprimirlo
void findByNumber(struct Persona* punteroPersonas, int personasLeidas)
{
    // variable para guardar que numero en el registro se va a buscar
    int registerNumber;
    printf("Ingrese un numero para mostrar ese registro del 0 al %d\n", personasLeidas - 1);
    scanf("%d", &registerNumber);

    // si esta dentro del rango lo imprime
    if (registerNumber <= personasLeidas - 1) {

        printf("%d) Nombre: %s, apellido: %s, fecha de nacimiento: %02d/%02d/%04d, edad: %d\n",
            registerNumber,
            punteroPersonas[registerNumber].nombre,
            punteroPersonas[registerNumber].apellido,
            punteroPersonas[registerNumber].fechaNacimiento.dia,
            punteroPersonas[registerNumber].fechaNacimiento.mes,
            punteroPersonas[registerNumber].fechaNacimiento.anio,
            punteroPersonas[registerNumber].edad);
    }
}

// funcion la cual borra un elemento del struct y copia esos datos al archivo
int deleteByNumber(struct Persona* punteroPersonas, int* personasLeidas)
{

    // variable para saber que numero ingreso el usuario
    int registerNumberToDelete;
    printf("Seleccione un numero para borrarlo del 0 al %d\n", *personasLeidas - 1);
    scanf("%d", &registerNumberToDelete);

    // chequea que el numero este entre 0 y el numero de personas y si no termina el programa
    if (registerNumberToDelete < 0 || registerNumberToDelete >= *personasLeidas - 1) {
        printf("Numero invalido");
        return 1;
    }

    // busca el archivo para escribirlo en binario (borra todo al hacer wb)
    FILE* archivo = fopen("DatosImportados.dat", "wb");
    if (archivo == NULL) {
        printf("hubo un error");
        return 1;
    }

    // desde el numero que ingreso el usuario setea el siguiente valor a ese
    // moviendo todos los elementos 1 hacia atras desde el numero que ingreso el usuario
    for (int i = registerNumberToDelete; i < *personasLeidas - 1; i++) {
        punteroPersonas[i] = punteroPersonas[i + 1];
    }

    // resta la cantidad de personas leidas
    (*personasLeidas)--;

    // escribe la nueva info y cierra el archivo
    fwrite(punteroPersonas, sizeof(struct Persona), *personasLeidas, archivo);
    fclose(archivo);

    // e indica que se realizo la operacion
    printf("Se ha borrado el registro %d\n", registerNumberToDelete);
}
// fucion la cual pregunta por un numero, muestra la info y la edita
int editByNumber(struct Persona* punteroPersonas, int personasLeidas)
{
    // variable para pedir que numero se quiere editar
    int registerNumberToEdit;
    printf("Seleccione un numero del 0 al %d para editar\n", personasLeidas - 1);
    scanf("%d", &registerNumberToEdit);

    // lo muestra y luego pide la nueva info
    printf("%d) Nombre: %s, Apellido: %s, Fecha de nacimiento: %d/%d/%d, Edad: %d\n",
        registerNumberToEdit,
        punteroPersonas[registerNumberToEdit].nombre,
        punteroPersonas[registerNumberToEdit].apellido,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.dia,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.mes,
        punteroPersonas[registerNumberToEdit].fechaNacimiento.anio,
        punteroPersonas[registerNumberToEdit].edad);

    printf("Ingrese nuevo NOMBRE APELLIDO FECHA(DD/MM/AAAA) y EDAD\n");
    scanf("%s %s %d/%d/%d %d",
        punteroPersonas[registerNumberToEdit].nombre,
        punteroPersonas[registerNumberToEdit].apellido,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.dia,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.mes,
        &punteroPersonas[registerNumberToEdit].fechaNacimiento.anio,
        &punteroPersonas[registerNumberToEdit].edad);

    // abre el archivo, escribe la nueva info y lo cierra
    FILE* archivo = fopen("DatosImportados.dat", "wb");
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
    FILE* archivo = fopen("DatosImportados.dat", "rb");
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
        findByNumber(personas, personasLeidas);
        break;
    case 3:
        deleteByNumber(personas, &personasLeidas);
        break;
    case 4:
        editByNumber(personas, personasLeidas);
        break;

    default:
        break;
    }
}