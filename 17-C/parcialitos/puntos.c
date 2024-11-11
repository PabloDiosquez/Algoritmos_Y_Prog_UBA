// Escribir en C un programa que pida al usuario dos palabras. El programa debe imprimir ambas palabras
// en una línea, separadas por una secuencia de puntos de forma tal que la longitud total de la línea
// sea de 30 caracteres. Ejemplo:

// Primera palabra: Hola
// Segunda palabra: Mundo
// Hola.....................Mundo

#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 30

/**
 * Imprime dos palabras separadas por puntos, de manera que la longitud total de la línea
 * sea de 30 caracteres.
 * 
 * La función calcula la cantidad de puntos necesarios para completar la línea de 30 caracteres
 * entre las dos palabras y luego imprime el resultado.
 * 
 * @param s La primera palabra que se imprimirá.
 * @param w La segunda palabra que se imprimirá.
 */
void imprimir_linea(char *s, char *w){
    printf("%s", s);
    for (size_t i = 0; i < MAX_CARACTERES - strlen(s) - strlen(w); i++)
    {
        printf(".");
    }
    printf("%s\n", w);
}

/**
 * Función principal que solicita al usuario dos palabras y luego las imprime en una línea
 * con puntos en medio, asegurando que la longitud total de la línea sea de 30 caracteres.
 * 
 * @return 0 al finalizar correctamente.
 */
int main(void){
    char s[15], w[15];

    printf("Ingrese la primera palabra: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; 

    printf("Ingrese la segunda palabra: ");
    fgets(w, sizeof(w), stdin);
    w[strcspn(w, "\n")] = '\0'; 

    imprimir_linea(s, w);
    
    return 0;
}