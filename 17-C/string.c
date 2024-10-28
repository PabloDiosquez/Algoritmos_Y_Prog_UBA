// Implemente sus propias versiones de las funciones de la biblioteca string.h que se detallan:

#include <stddef.h>

// size_t strlen(const char * );

/**
 * @brief Calcula la longitud de una cadena de caracteres.
 * 
 * Esta función implementa una versión personalizada de la función estándar `strlen` de la biblioteca `<string.h>`.
 * Recorre cada carácter de la cadena de entrada hasta encontrar el carácter nulo (`'\0'`), que marca el final de la cadena.
 * Devuelve el número de caracteres que se encuentran antes del carácter nulo, es decir, la longitud de la cadena.
 * 
 * @param s Puntero a la cadena de caracteres cuya longitud se desea calcular.
 * @return size_t Longitud de la cadena, excluyendo el carácter nulo final.
 */
size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// char * strcpy(char * dest, const char * orig);

// char * strncpy(char * dest, const char * orig, size_t n);

// int strcmp(const char * s1, const char * s2);

// int strncmp(const char * s1, const char * s2, size_t n);

// char * strcat(char * dest, const char * orig);

// void * memmove(void * dest, const void * src, size_t n);

// void * memcpy(void * dest, const void * src, size_t n);

// int memcmp(const void * s1, const void * s2, size_t n);

// Si bien no pertenecen al estándar ISO sino al BSD:

// int strcasecmp(const char * s1, const char *s2); que funciona como strcmp() pero es case insensitive.

// int strncasecmp(const char *s1, const char *s2, size_t n);