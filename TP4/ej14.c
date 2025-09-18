/*
Revise el programa del ejercicio E11TP2 y proponga al menos tres funciones que podría extraer del código. Determine la declaración de las funciones indicando tipo de retorno, nombre y parámetros de entrada con sus tipos. Si lo desea, implemente las funciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sentenceLengthArray 30
#define arrayLength 1000
#define sentenceLength 100

// toma un array de caracetres, si no es nulo
// busca en que posicion del array se encuentra el primero \n y lo reemplaza con \0
// para indicar que se termino el array
void replaceWithArrayEnd(char* array)
{
    if (array != NULL) {
        array[strcspn(array, "\n")] = '\0';
    }
}

// funcion 1, pedir oracion al usuario y guardarla
// con retorno void ya que toma como arg el puntero del userSentence
void askForSentence(char* pointerUserSentence)
{
    printf("\n\nIngrese una oracion, si se ingresa fin se detiene el programa: \n");

    // guarda la palabra/s en el array
    fgets(pointerUserSentence, sentenceLength, stdin);

    // funcion que reemplaza el salto de linea con \0 para denotar el termino del array
    replaceWithArrayEnd(pointerUserSentence);
}

// funcion 2 separar palabras
// retorna void porque toma como parametros, los valores en memoria de userSentence (el primer elemento), el array de words (todo completo por eso es **), y el wordCount(valor)
void separateWords(char* pointerUserSentence, char** pointerWords, int* pointerWordCount)
{

    // toma la oracion ingresada por le usuario y busca los primeros caracteres validos hasta que encuentra " ,.;:!?"
    // y la asigna como ultima palabra validad
    char* lastValidWord = strtok(pointerUserSentence, " ,.;:!?");

    // mientras que los la ultima palabra valida no sean null
    // y la cantidad de palabras ingresada sea menor al largo maximo de la oracion (100 caracteres)
    while (lastValidWord != NULL && *pointerWordCount < sentenceLength) {

        // para la palabra en words, con posicion wordcount (de 0 hasta 100)
        // le asigna bytes en memoria igual al largo de la ultima palabra mas uno
        // para el caracter nulo
        pointerWords[*pointerWordCount] = malloc(strlen(lastValidWord) + 1);

        // copia la ultima palabra valida en la ultima posicion
        strcpy(pointerWords[*pointerWordCount], lastValidWord);

        // suma al contador de palabras
        (*pointerWordCount)++;

        // le asigna la ultima palabra valida a la variable
        // null indica que continue con la misma variable anterior
        lastValidWord = strtok(NULL, " ,.;:!?");
    }
}

int main()
{
    // inicializacion de las variables para la oracion que ingresa el usuaria
    // y el diccionario con palabras comunes hardcodeadas
    char userSentence[sentenceLength], dictionary[arrayLength][sentenceLengthArray] = { "la", "de", "que", "el", "en", "y", "a", "los", "se", "del", "las", "por", "un", "con", "no", "una", "su", "para", "es", "al", "lo", "como", "más", "o", "pero", "sus", "le", "han", "sin", "sobre", "este", "ya", "entre", "cuando", "todo", "esta", "ser", "son", "dos", "también", "fue", "había", "era", "muy", "años", "hasta", "desde", "está", "mi", "porque", "él", "cuando", "tú", "sí", "nos", "ni", "contra", "tú", "él", "ella", "ellos", "nosotros", "vosotros", "ellos", "sí", "no", "cada", "otro", "sus", "mi", "nuestro", "tu", "su", "sus", "nuestro", "nuestra", "nuestros", "nuestras", "vuestro", "vuestra", "vuestros", "vuestras", "este", "esta", "estos", "estas", "aquel", "aquella", "aquellos", "aquellas", "alguno", "alguna", "algunos", "algunas", "ninguno", "ninguna", "ningunos", "ningunas", "otro", "otra" };

    // inicializacion de variable que contiene el numero de la cantidad de palabras
    // harcodeades en el diccionario
    int dictionaryCount = 87;

    // while loop que corre durante toda la ejecucion hasta que se escriba la palabra fin
    while (1) {

        askForSentence(userSentence);

        // compara si la palabra ingresada fue fin, y finaliza el while loop
        if (strcmp(userSentence, "fin") == 0) {
            break;
        }

        // variable puntero en el cual se separa la oracion ingresada por el usuario en array de palabras singulares
        char* words[sentenceLength];

        // inicializacion de la cantidad de palabras, 0 por defecto
        int wordCount = 0;

        separateWords(userSentence, words, &wordCount);

        // si la palabra ingresada por el usario no esta vacia
        if (userSentence != NULL) {

            // inicializacion de variable para contar cuando se encuentra una palabra repetida
            int wordFoundInDictionary = 0;

            // doble for loop, para tomar la primera palabra ingresada por el usuario [i], y chequear por todo el diccionario [j]
            // antes de pasar a la siguiente palabra
            for (int i = 0; i < wordCount; i++) {

                // setea la palabra encontrada en 0 para cada ciclo de i
                // osea para cada nueva palabra en el array de palabras ingresadas por el usuario
                wordFoundInDictionary = 0;

                // loopea chequeando si la palabra en posicion i se encuentra en
                // alguno de los lugares en j, devuelvo 0 si se encontro
                for (int j = 0; j < arrayLength; j++) {
                    if (strcmp(words[i], dictionary[j]) == 0) {

                        // setea la variable como true (1)
                        wordFoundInDictionary = 1;

                        // finaliza el bucle una vez se encontro un repetido
                        break;
                    }
                }

                // variable en la cual ingresara si/no+\0 ingresado automaticamente
                char addToDictionary[3];

                // si no se encontro en el diccionario
                // le pregunta al usario si desea agregarla
                if (wordFoundInDictionary == 0) {

                    printf("\nla palabra '%s' no esta en el dicionario, escriba si/no para agregarla ", words[i]);

                    // toma la respuesta, y donde encuentre el salto de linea \n lo asigna por un \0 para indicar la terminacion
                    fgets(addToDictionary, sizeof(addToDictionary), stdin);
                    replaceWithArrayEnd(addToDictionary);

                    // limpia caracteres residuales en el input
                    getchar();
                    // si responde que si, y el numero de palabras es menor al numero maximo de palabras -1, para el \0, se agrega al ultimo lugar del diccionario
                    if (strcmp(addToDictionary, "si") == 0 && dictionaryCount < arrayLength - 1) {
                        printf("\nSe agrego al dicionario\n");

                        // copia en el diccionario, en el ultimo logar registrado, la palabra en el array word
                        strcpy(dictionary[dictionaryCount], words[i]);

                        // se suma para saber cual es el ultimo lugar del diccionario
                        dictionaryCount++;
                    } else {
                        printf("\nno se agrego al diccionario\n");
                    }
                }
            }
        }

        // se imprime el diccionario actualizado una vez que se analizo la oracion ingresada por el uruario
        printf("\ndiccionario actualizado:\n");
        for (int i = 0; i < dictionaryCount; i++) {
            printf("%s ", dictionary[i]);
        }

        // libera el espacio de la memoria
        for (int i = 0; i < wordCount; i++) {
            free(words[i]);
        }
    }
}