/*
Escriba un programa que contenga un arreglo de longitud 1000 de cadenas de texto de hasta 30
caracteres cada una. El programa debe permitir al usuario ingresar una oración y luego verificar si las palabras
de la oración están presentes en el arreglo (diccionario) o no. Si una palabras no está presente, el programa
debe indicarla y darle la opción al usuario de agregarla. Al terminar de analizar el texto, el programa debe
imprimir el estado actual del diccionario. El programa termina con la palabras “fin”.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sentenceLengthArray 30
#define arrayLength 1000
#define sentenceLength 100

// funcion utilizada para limbiar el buffer del input
// mientras que character no se un salto lee
void clearInputBuffer()
{
    int character;
    while ((character = getchar()) != '\n')
        ;
}

// toma un array de caracetres, si no es nulo
// busca en que posicion del array se encuentra el primero \n y lo reemplaza con \0
// para indicar que se termino el array
void replaceWithArrayEnd(char* array)
{
    if (array != NULL) {
        array[strcspn(array, "\n")] = '\0';
    }
}

int main()
{
    // inicializacion de las variables para la oracion que ingresa el usuaria
    // y el diccionario con palabras comunes hardcodeadas
    char userSentence[sentenceLength], dictionary[arrayLength][sentenceLengthArray] = { "la", "de", "que", "el", "en", "y", "a", "los", "se", "del", "las", "por", "un", "con", "no", "una", "su", "para", "es", "al", "lo", "como", "más", "o", "pero", "sus", "le", "han", "sin", "sobre", "este", "ya", "entre", "cuando", "todo", "esta", "ser", "son", "dos", "también", "fue", "había", "era", "muy", "años", "hasta", "desde", "está", "mi", "porque", "él", "cuando", "tú", "sí", "nos", "ni", "contra", "tú", "él", "ella", "ellos", "nosotros", "vosotros", "ellos", "sí", "no", "cada", "otro", "sus", "mi", "nuestro", "tu", "su", "sus", "nuestro", "nuestra", "nuestros", "nuestras", "vuestro", "vuestra", "vuestros", "vuestras", "este", "esta", "estos", "estas", "aquel", "aquella", "aquellos", "aquellas", "alguno", "alguna", "algunos", "algunas", "ninguno", "ninguna", "ningunos", "ningunas", "otro", "otra" };

    // inicializacion de variable que contiene el numero de la cantidad de palabras
    //  harcodeades en el diccionario
    int dictionaryCount = 87;

    // while loop que corre durante toda la ejecucion hasta que se escriba la palabra fin
    while (1) {
        printf("\n\nIngrese una oracion, si se ingresa fin se detiene el programa: \n");

        // guarda la palabra/s en el array
        fgets(userSentence, sizeof(userSentence), stdin);

        // funcion que reemplaza el salto de linea con \0 para denotar el termino del array
        replaceWithArrayEnd(userSentence);

        // si ACA ME QUEDE
        if (strcmp(userSentence, "fin") == 0) {
            break;
        }

        // loopea por el array y chequea si la palabra se encuentra
        char* words[sentenceLengthArray * 3];
        int wordCount = 0;
        // toma la oracion, busca uno de los limitadores que estan entre " "
        // devuelve el punto a la primera palabra valida
        char* lastValidWord = strtok(userSentence, " ,.;:!?");

        // mientras que los la ultima palabra valida no sean null
        // y la cantidad de palabras sea menor al largo maximo de la oracion
        while (lastValidWord != NULL && wordCount < sentenceLengthArray * 3) {
            // para la palabra en words, con posicion wordcount
            // le asigna bytes en memoria igual al largo de la ultima palabra mas uno
            // para el caracter nulo
            words[wordCount] = malloc(strlen(lastValidWord) + 1);

            // copia la ultima palabra valida en la ultima posicion
            strcpy(words[wordCount], lastValidWord);
            wordCount++;

            // le asigna la ultima palabra valida a la variable
            // null indica que continue con la misma variable anterior
            lastValidWord = strtok(NULL, " ,.;:!?");
        }

        // si la palabra ingresada por el usario no esta vacia
        if (userSentence != NULL) {
            int wordFoundInDictionary = 0;
            // muestra las palabras separadas
            printf("\npalabras separadas\n");
            for (int i = 0; i < wordCount; i++) {
                wordFoundInDictionary = 0;
                printf("\npalabra %d: %s\n", i + 1, words[i]);

                // loopea chequeando si la palabra en posicion i se encuentra en
                // alguno de los lugares en j, devuelvo 0 si se encontro
                for (int j = 0; j < arrayLength; j++) {
                    if (strcmp(words[i], dictionary[j]) == 0) {
                        // setea la variable como true (1)
                        wordFoundInDictionary = 1;
                        // imprime la palabra y su posicion
                        printf("\n%s en posicion: %i en posicion esta repetida\n", words[i], j);
                    }
                }

                // si no se encontro en el diccionario
                // le pregunta al usario si desea agregarla
                char addToDictionary[3];
                if (wordFoundInDictionary == 0) {
                    printf("\nNo esta en el dicionario, ingrese si o no si desea agregarla\n");
                    fgets(addToDictionary, sizeof(addToDictionary), stdin);
                    replaceWithArrayEnd(addToDictionary);

                    // limpia caracteres residuales en el input
                    clearInputBuffer();

                    // si responde que si, agrega al ultimo lugar del diccionario
                    if (strcmp(addToDictionary, "si") == 0) {
                        printf("\nSe agrego al dicionario\n");
                        if (dictionaryCount < arrayLength) {
                            strcpy(dictionary[dictionaryCount], words[i]);
                            printf("\n%s\n", dictionary[dictionaryCount]);
                            dictionaryCount++;
                        }
                    }
                }
            }
        }

        printf("diccionario actualizado");
        for (int i = 0; i < dictionaryCount; i++) {
            printf("%s ", dictionary[i]);
        }
        // libera el espacio de la memoria
        for (int i = 0; i < wordCount; i++) {
            free(words[i]);
        }
    }
}