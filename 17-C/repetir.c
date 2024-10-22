#include <stdlib.h>

/**
 * @brief Repite una cadena de texto un número dado de veces y devuelve la cadena resultante.
 *
 * Esta función toma una cadena de texto `s` y un número entero `n`, y crea una nueva cadena
 * de texto que contiene la cadena `s` repetida `n` veces. La nueva cadena se almacena en el 
 * heap (memoria dinámica), por lo que es responsabilidad del llamante liberar la memoria 
 * con `free` cuando ya no sea necesaria. La cadena devuelta termina con un carácter nulo ('\0').
 *
 * @param s La cadena de texto que se desea repetir.
 * @param n El número de veces que se repetirá la cadena `s`.
 * @return Un puntero a la nueva cadena que contiene `s` repetida `n` veces. 
 *         Si la asignación de memoria falla, se devuelve `NULL`.
 *
 * @note Es responsabilidad del usuario liberar la memoria devuelta utilizando `free()`.
 */
char* repetir(const char* s, size_t n) {
    size_t len = strlen(s);              
    char* buf = malloc(n * len + 1);      

    if (buf == NULL) {                   
        return NULL;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; s[j] != '\0'; j++) {
            buf[j + len * i] = s[j];
        }
    }

    buf[len * n] = '\0';                  
    return buf;
}