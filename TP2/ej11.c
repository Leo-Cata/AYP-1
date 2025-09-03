#include <stdio.h>
#include <string.h>
#define arrayLength 1000
#define sentenceLength 30
/*
Escriba un programa que contenga un arreglo de longitud 1000 de cadenas de texto de hasta 30
caracteres cada una. El programa debe permitir al usuario ingresar una oración y luego verificar si las palabras
de la oración están presentes en el arreglo (diccionario) o no. Si una palabra no está presente, el programa
debe indicarla y darle la opción al usuario de agregarla. Al terminar de analizar el texto, el programa debe
imprimir el estado actual del diccionario. El programa termina con la palabra “fin”.
*/
int main()
{
    char *dictionary[arrayLength][sentenceLength] = {
        "la", "de", "que", "el", "en", "y", "a", "los", "se", "del",
        "las", "por", "un", "con", "no", "una", "su", "para", "es", "al",
        "lo", "como", "más", "o", "pero", "sus", "le", "han", "sin", "sobre",
        "este", "ya", "entre", "cuando", "todo", "esta", "ser", "son", "dos", "también",
        "fue", "había", "era", "muy", "años", "hasta", "desde", "está", "mi", "porque", "él", "cuando", "tú", "sí", "nos", "ni", "contra", "tú", "él", "ella", "ellos", "nosotros", "vosotros", "ellos", "sí", "no", "cada", "otro", "sus", "mi", "nuestro", "tu", "su", "sus", "nuestro", "nuestra", "nuestros", "nuestras", "vuestro", "vuestra", "vuestros", "vuestras", "este", "esta", "estos", "estas", "aquel", "aquella", "aquellos", "aquellas", "alguno", "alguna", "algunos", "algunas", "ninguno", "ninguna", "ningunos", "ningunas", "otro", "otra"
    },
         *userSentence[sentenceLength * 3] = { "" };

    while (userSentence != "fin") {
        printf("Ingrese una oracion\n");
        fgets(&userSentence, sizeof(userSentence), stdin);
    }
}