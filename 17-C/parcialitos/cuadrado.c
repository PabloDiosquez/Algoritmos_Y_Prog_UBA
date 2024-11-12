// Escribir en lenguaje C un programa que pida al usuario un número n e imprima un cuadrado
// de lado n formado por asteriscos. Ejemplo:

// Ingrese un numero: 4
// ****
// *  *
// *  *
// ****

#include <stdio.h>
#define CARACTER '*'

/**
 * Imprime una línea de longitud n con el carácter especificado.
 * 
 * @param n Tamaño de la línea a imprimir.
 * @param c Carácter con el que se imprime la línea.
 */
void imprimir_linea(size_t n, char c) {
    for (size_t i = 0; i < n; i++) {
        printf("%c", c);
    }
}

/**
 * Imprime un cuadrado de lado n usando el carácter definido.
 * 
 * @param n Tamaño del lado del cuadrado.
 */
void imprimir_cuadrado(size_t n) {
    if(n < 1){
        return; 
    }
    
    imprimir_linea(n, CARACTER);
    printf("\n");

    for (size_t i = 0; i < n - 2; i++) {
        printf("%c", CARACTER);
        imprimir_linea(n - 2, ' ');
        printf("%c\n", CARACTER);
    }

    imprimir_linea(n, CARACTER);
    
}

/**
 * Programa principal que solicita al usuario un número e imprime un cuadrado
 * con lados de longitud n usando asteriscos.
 * 
 * @return 0 Indica que el programa terminó correctamente.
 */
int main(void) {
    size_t n = 5;
    imprimir_cuadrado(n);
    return 0;
}