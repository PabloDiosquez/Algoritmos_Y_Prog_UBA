// Escribir un programa en C que le pida al usuario que ingrese una cadena y luego muestre por pantalla
// esa cadena pero reemplazando cada vocal por un *.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CARACTER '*'  

/**
 * @brief Verifica si un carácter es una vocal.
 *
 * @param c El carácter a verificar.
 * @return true si el carácter es una vocal, false en caso contrario.
 */
bool es_vocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

/**
 * @brief Reemplaza las vocales en una cadena por un carácter dado.
 *
 * Esta función recorre la cadena de caracteres, y reemplaza cada vocal por el valor
 * de `CARACTER`. Los caracteres no vocales se mantienen sin cambios.
 *
 * @param s La cadena original a modificar.
 * @return Un puntero a una nueva cadena con las vocales reemplazadas, o NULL si hay un error en la asignación de memoria.
 */
char *reemplazar_vocales(const char *s) {
    char *d = malloc((strlen(s) + 1) * sizeof(char));
    if (d == NULL) {
        return NULL;  
    }

    size_t i = 0;
    for (; s[i] != '\0'; i++) {
        if (es_vocal(s[i])) {
            d[i] = CARACTER;  
        } else {
            d[i] = s[i];  
        }
    }

    d[i] = '\0';  

    return d;  
}

int main() {
    const char *texto = "Hola Mundo";
    char *resultado = reemplazar_vocales(texto);

    if (resultado != NULL) {
        printf("Texto original: %s\n", texto);
        printf("Texto modificado: %s\n", resultado);
        free(resultado);  
    } else {
        printf("Error en la asignación de memoria.\n");
    }

    return 0;
}