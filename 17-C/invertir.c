// Implementar la función void invertir(char *s) que invierte la cadena s (in-
// place).

#include <string.h>
#include <stdio.h>

/**
 * Intercambia dos caracteres en las posiciones i y j de una cadena.
 *
 * @param s Un puntero a la cadena de caracteres.
 * @param i El índice del primer carácter a intercambiar.
 * @param j El índice del segundo carácter a intercambiar.
 */
void swap(char* s, int i, int j) {
    char aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}

/**
 * Invierte una subcadena de la cadena s en el rango [d, h].
 *
 * @param s Un puntero a la cadena de caracteres.
 * @param d El índice de inicio del rango a invertir.
 * @param h El índice final del rango a invertir.
 */
void _invertir(char* s, size_t d, size_t h) {
    while (d < h) {
        swap(s, d, h);
        d++;
        h--;
    }
}

/**
 * Invierte una cadena de caracteres completa.
 *
 * @param s Un puntero a la cadena de caracteres que se va a invertir.
 */
void invertir(char* s) {
    _invertir(s, 0, strlen(s) - 1);
}

int main(void) {
    char s[5] = "hola";
    invertir(s);

    printf("%s\n", s);

    return 0;
}