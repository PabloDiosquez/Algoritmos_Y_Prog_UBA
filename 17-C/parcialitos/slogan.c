// Escribir en C una función que reciba una cadena con un nombre y un número N, e imprima un slogan. 
// Un slogan se forma con:

// Las 2 primeras letras de la cadena seguidas por una coma, repetido N veces separado por un espacio
// El nombre seguido de un espacio
// Las 2 primeras letras de la cadena seguidas por la segunda letra de la cadena repetida N veces.
// Ej:

// Para "Simona" y 3 debe imprimir "Si, Si, Si, Simona Siiii";
// Para "Aranguren" y 2 debe imprimir "Ar, Ar, Aranguren Arrr"

#include <stdio.h>

/**
 * Imprime un eslogan formado por:
 * - Las dos primeras letras del nombre seguidas de una coma, repetido N veces, separado por un espacio.
 * - El nombre seguido de un espacio.
 * - Las dos primeras letras del nombre seguidas por la segunda letra repetida N veces.
 *
 * @param nombre Cadena de caracteres que contiene el nombre.
 * @param n Número de veces que se debe repetir las dos primeras letras del nombre en la primera parte del eslogan.
 */
void imprimir_slogan(char *nombre, int n){
    for (int i = 0; i < n; i++) {
        printf("%c%c, ", nombre[0], nombre[1]);
    }

    printf("%s ", nombre);

    printf("%c%c", nombre[0], nombre[1]);
    for (int i = 0; i < n; i++) {
        printf("%c", nombre[1]);
    }

    printf("\n");
}

int main(void){
    imprimir_slogan("Simona", 3);  // Imprime "Si, Si, Si, Simona Siiii"
    return 0;
}
