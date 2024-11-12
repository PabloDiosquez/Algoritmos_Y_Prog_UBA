// Escribir en lenguaje C una función que recibe una cadena de caracteres e imprime la cantidad de
// apariciones de cada caracter. Ejemplo:

// caracteres("Barbara")
// a: 3
// b: 1
// r: 2
// B: 1
// Ayuda: recordar que cada caracter (char) es un número entre 0 y 255. Usar un arreglo de 255 
// posiciones para contar la cantidad de ocurrencias de cada caracter.

#include <stdio.h>

/**
 * @brief Imprime la cantidad de apariciones de cada carácter en una cadena.
 *
 * Esta función recorre la cadena de caracteres recibida y utiliza un arreglo
 * de 256 posiciones para contar las ocurrencias de cada carácter. Luego, imprime
 * los caracteres que aparecen al menos una vez en la cadena junto con su respectiva
 * cantidad de apariciones.
 *
 * @param s La cadena de caracteres cuya frecuencia de aparición se desea contar.
 */
void caracteres(char *s) {
    char cs[256] = {0};
    for (size_t i = 0; s[i] != '\0'; i++) {
        cs[(int)s[i]]++;
    }

    printf("Caracteres:\n");
    for (size_t i = 0; i < 256; i++) {
        if (cs[i] > 0) {
            printf("%c: %d\n", i, cs[i]);
        }
    }
}

/**
 * @brief Función principal que llama a la función `caracteres` para contar
 *        las apariciones de los caracteres en una cadena de ejemplo.
 * 
 * @return 0 si la ejecución fue exitosa.
 */
int main(void) {
    caracteres("Barbara");
    return 0;
}