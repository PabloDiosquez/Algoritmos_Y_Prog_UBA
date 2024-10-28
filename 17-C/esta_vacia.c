// Escriba un programa que lea una cadena de caracteres y verifique si la misma se encuentra vacía.

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Verifica si una cadena de caracteres está vacía.
 * 
 * Una cadena se considera vacía si es un puntero nulo o si su primer carácter es el carácter nulo ('\0'),
 * lo cual indica que no contiene caracteres visibles. Esto incluye casos en los que solo se ingresó
 * un salto de línea.
 * 
 * @param s Puntero a la cadena de caracteres a verificar.
 * @return true Si la cadena está vacía o es nula.
 * @return false Si la cadena no está vacía.
 */
bool esta_vacia(const char* s) {
    return s == NULL || s[0] == '\0';
}

/**
 * @brief Programa principal que lee una cadena de caracteres y verifica si está vacía.
 * 
 * El programa solicita al usuario que ingrese una cadena de caracteres. Luego, llama a la función
 * `esta_vacia` para determinar si la cadena está vacía o no. Si la cadena ingresada es vacía,
 * muestra un mensaje indicando que se ingresó una cadena vacía. En caso contrario, muestra
 * un mensaje genérico.
 * 
 * @return int Valor de retorno del programa. Devuelve 0 si se ejecuta correctamente.
 */
int main(void) {
    char entrada[100];
    printf("Ingrese la cadena: ");
    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        // Elimina el carácter de nueva línea si está presente.
        size_t longitud = strlen(entrada);
        if (longitud > 0 && entrada[longitud - 1] == '\n') {
            entrada[longitud - 1] = '\0';
        }
        if (esta_vacia(entrada)) {
            printf("Ingresaste una cadena vacía!\n");
        } else {
            printf("La cadena no está vacía.\n");
        }
    } else {
        printf("Error al leer la cadena.\n");
    }
    return 0;
}