/*
Escribí un programa que muestre un menú que permita realizar las siguientes operaciones:
1. Ingresar puntos geográficos, indicando nombre, latitud y longitud (p.e. “Mi casa”, -42.768658,
-65.0526139). La latitud y longitud deben ingresarse en formato float y guardarse junto con el
nombre en un registro dentro de un arreglo.
2. Calcular la distancia entre dos puntos (usar la fórmula de Haversine), indicando nombre del punto 1 y
nombre del punto 2.
*/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define maxNameLength 30
#define maxGeoPointArrayLength 10

// struct dado por le ej
struct GeoPoint {
    char nombre[maxNameLength];
    float latitud;
    float longitud;
};

// funcion para pedir datos y guardarlos
void saveNewGeoPointData(struct GeoPoint* pointerGeoPointData, int* pointerGeoPointCounter)
{
    // pide nombre y toma hasta el \n
    printf("\nIngrese un nombre\n");
    scanf(" %29[^\n]", &pointerGeoPointData[*pointerGeoPointCounter].nombre);

    // limpia el buffer
    getchar();
    // pide latitud y longitud
    printf("Ingrese latitud y longitud\n");
    scanf("%f %f", &pointerGeoPointData[*pointerGeoPointCounter].latitud, &pointerGeoPointData[*pointerGeoPointCounter].longitud);

    // limpia el buffer
    getchar();

    // muestra que datos se guardaron
    printf("se ha guardado: nombre: %s, latitud: %f, longitud: %f\n",
        pointerGeoPointData[*pointerGeoPointCounter].nombre,
        pointerGeoPointData[*pointerGeoPointCounter].latitud,
        pointerGeoPointData[*pointerGeoPointCounter].longitud);

    // incrementa el contador de geoPoints guardados
    (*pointerGeoPointCounter)++;
};

// funcion que imprime todo los datos de geoPoint
void printAllGeoPointData(struct GeoPoint* GeoPointData, int GeoPointCounter)
{
    printf("datos guardados:\n");

    // desde 0 hasta la cantidad que hay en el counter imprime todo
    for (int i = 0; i < GeoPointCounter; i++) {
        printf("%d) nombre: %s, latitud: %f, longitud: %f\n",
            i + 1,
            GeoPointData[i].nombre,
            GeoPointData[i].latitud,
            GeoPointData[i].longitud);
    }
}

void calculateGeoPointsDistances(float latitud1, float latitud2, float longitud1, float longitud2, char firstCity[], char secondCity[])
{
    // pi porque M_PI tirar error
    double pi = 3.14159265358979323846;

    // transforma las latitudes y longitudes a radianes para hacer el calc correctamente
    double lat1Rad = latitud1 * pi / 180;
    double lat2Rad = latitud2 * pi / 180;
    double long1Rad = longitud1 * pi / 180;
    double long2Rad = longitud2 * pi / 180;

    //
    double distanceLatitud = lat2Rad - lat1Rad;
    double distanceLongitud = long2Rad - long1Rad;
    double a = pow(sin(distanceLatitud / 2), 2) + cos(lat1Rad) * cos(lat2Rad) * pow(sin(distanceLongitud / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distancia = 6371 * c;

    // imprime las distancias
    printf("distancia entre %s y %s es: %.2fkm\n\n", firstCity, secondCity, distancia);
};

// funcion para calcular las distancias
void selectGeoPointsToCalculate(struct GeoPoint* pointerGeoPointData, int geoPointCounter)
{
    // le muestra todos los datos guardados al usuario
    printAllGeoPointData(pointerGeoPointData, geoPointCounter);

    // crea variables con numeros ingresados correspondientes y despues de tener los valores, le resta 1 a ambos para obtener de 0 a 10
    int savedData1, savedData2;
    printf("Seleccione 2 lugares guardados para calcular las distancias\n");
    scanf("%d %d", &savedData1, &savedData2);
    savedData1--;
    savedData2--;

    calculateGeoPointsDistances(
        pointerGeoPointData[savedData1].latitud, pointerGeoPointData[savedData2].latitud,
        pointerGeoPointData[savedData1].longitud, pointerGeoPointData[savedData2].longitud,
        pointerGeoPointData[savedData1].nombre, pointerGeoPointData[savedData2].nombre);
};

int main()
{
    // struct del geopoint, y contador de cuantos elementos hay
    struct GeoPoint geoPoint[maxGeoPointArrayLength];
    int geoPointCounter = 0;

    // loop para el menu
    while (true) {
        int userMenuInput = 0;
        printf("\ningrese 1 para guardar datos geograficos, 2 imprimer todos los datos, 3 para calcular las distancias, 4 para terminar el programa\n");
        scanf("%d", &userMenuInput);

        // logica para seleccionar el menu
        if (userMenuInput == 1) {
            saveNewGeoPointData(geoPoint, &geoPointCounter);
        } else if (userMenuInput == 2) {
            printAllGeoPointData(geoPoint, geoPointCounter);
        } else if (userMenuInput == 3 && geoPointCounter >= 2) {
            selectGeoPointsToCalculate(geoPoint, geoPointCounter);
        } else if (userMenuInput == 4) {
            printf("Cerrando el programa...\n");
            break;
        } else {
            printf("valor invalido");
        }
    }
};