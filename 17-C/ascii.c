// Escriba un programa que lea una cadena de caracteres e imprima por pantalla, para cada elemento
// de la cadena: su posición dentro de la cadena, el carácter y su código en representación ASCII.

#include <stdio.h>
#include <stddef.h>

/**
 * @brief Imprime la posición, el carácter y su código ASCII para cada elemento de una cadena.
 * 
 * Esta función recorre una cadena de caracteres y, para cada carácter, imprime su
 * posición en la cadena, el propio carácter, y su valor en la representación ASCII.
 * La función detiene el recorrido cuando encuentra el carácter nulo ('\0') o un salto de línea ('\n').
 * 
 * @param s Puntero a la cadena de caracteres a analizar. Debe ser una cadena nula terminada.
 */
void analizar_cadena(const char *s) {
    size_t i;
    for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        printf("%zu  %c  %d\n", i, s[i], s[i]);
    }
}

/**
 * @brief Programa principal que lee una cadena de caracteres e invoca la función de análisis.
 * 
 * El programa solicita al usuario que ingrese una cadena de caracteres, la cual se almacena en
 * un arreglo de tamaño fijo. Luego, se llama a la función `analizar_cadena` para procesar
 * la entrada proporcionada. La función `fgets` se utiliza para leer la cadena de manera segura,
 * evitando desbordamientos.
 * 
 * @return int Valor de retorno del programa. Devuelve 0 si se ejecuta correctamente.
 */
int main(void) {
    char entrada[20];
    printf("Ingrese la cadena: ");
    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        analizar_cadena(entrada);
    }
    return 0;
}