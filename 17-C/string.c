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

/**
 * @brief Copia una cadena de caracteres de origen en una cadena de destino.
 * 
 * Esta función implementa una versión personalizada de la función estándar `strcpy` de la biblioteca `<string.h>`.
 * Copia cada carácter de la cadena `orig` a la cadena `dest`, incluyendo el carácter nulo (`'\0'`) al final.
 * La cadena `dest` debe tener suficiente espacio para contener la cadena `orig`.
 * 
 * @param dest Puntero al arreglo de destino donde se copiará la cadena.
 * @param orig Puntero a la cadena de caracteres de origen.
 * @return char* Retorna un puntero a la cadena de destino `dest`.
 */
char *strcpy(char *dest, const char *orig) {
    size_t i;
    for (i = 0; orig[i] != '\0'; i++) {
        dest[i] = orig[i];
    }
    dest[i] = '\0'; // Agrega el carácter nulo al final de la cadena copiada
    return dest;
}


// char * strncpy(char * dest, const char * orig, size_t n);

/**
 * @brief Copia hasta `n` caracteres de una cadena de origen a una cadena de destino.
 * 
 * Esta función implementa una versión personalizada de `strncpy` de la biblioteca `<string.h>`.
 * Copia como máximo `n` caracteres de la cadena `orig` a la cadena `dest`. Si la longitud de `orig`
 * es menor que `n`, se rellenan los caracteres restantes en `dest` con el carácter nulo (`'\0'`).
 * La cadena `dest` debe tener suficiente espacio para almacenar `n` caracteres.
 * 
 * @param dest Puntero al arreglo de destino donde se copiará la cadena.
 * @param orig Puntero a la cadena de caracteres de origen.
 * @param n Número máximo de caracteres a copiar de `orig` a `dest`.
 * @return char* Retorna un puntero a la cadena de destino `dest`.
 */
char *strncpy(char *dest, const char *orig, size_t n) {
    size_t i;

    for (i = 0; i < n && orig[i] != '\0'; i++) {
        dest[i] = orig[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}


// int strcmp(const char * s1, const char * s2);

/**
 * @brief Compara dos cadenas de caracteres.
 * 
 * Esta función implementa una versión personalizada de la función estándar `strcmp` de la biblioteca `<string.h>`.
 * Compara carácter a carácter las cadenas `s1` y `s2`. Retorna un valor negativo si `s1` es menor que `s2`,
 * cero si son iguales, y un valor positivo si `s1` es mayor que `s2`.
 * 
 * @param s1 Puntero a la primera cadena de caracteres.
 * @param s2 Puntero a la segunda cadena de caracteres.
 * @return int Un valor negativo si `s1` es menor que `s2`, 0 si son iguales, o un valor positivo si `s1` es mayor que `s2`.
 */
int strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        unsigned char c1 = (unsigned char)(*s1++);
        unsigned char c2 = (unsigned char)(*s2++);
        
        if (c1 < c2) {
            return -1; 
        } else if (c1 > c2) {
            return 1; 
        }
    }

    return (unsigned char)(*s1) - (unsigned char)(*s2);
}

// int strncmp(const char * s1, const char * s2, size_t n);

// char * strcat(char * dest, const char * orig);

/**
 * @brief Concatenar dos cadenas de caracteres.
 * 
 * Esta función implementa una versión personalizada de la función estándar `strcat` de la biblioteca `<string.h>`.
 * La cadena `orig` se añade al final de la cadena `dest`. Se asume que `dest` tiene suficiente espacio
 * para contener la concatenación de ambas cadenas.
 * 
 * @param dest Puntero a la cadena de destino.
 * @param orig Puntero a la cadena de origen que se va a concatenar.
 * @return char* Un puntero a la cadena de destino.
 */
char *strcat(char *dest, const char *orig) {
    size_t i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    size_t j = 0;
    while (orig[j] != '\0') {
        dest[i] = orig[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    
    return dest; 
}

/**
 * @brief Concatenar dos cadenas de caracteres.
 * 
 * Esta función implementa una versión optimizada de la función estándar `strcat` de la biblioteca `<string.h>`.
 * La cadena `orig` se añade al final de la cadena `dest`. Se asume que `dest` tiene suficiente espacio
 * para contener la concatenación de ambas cadenas.
 * 
 * @param dest Puntero a la cadena de destino.
 * @param orig Puntero a la cadena de origen que se va a concatenar.
 * @return char* Un puntero a la cadena de destino.
 */
char *strcat(char *dest, const char *orig) {
    if (dest == NULL || orig == NULL) {
        return dest; 
    }

    char *ptr = dest;
    while (*ptr != '\0') {
        ptr++; 
    }

    while (*orig != '\0') {
        *ptr++ = *orig++; 
    }

    *ptr = '\0'; 

    return dest; 
}


// void * memmove(void * dest, const void * src, size_t n);

// void * memcpy(void * dest, const void * src, size_t n);

// int memcmp(const void * s1, const void * s2, size_t n);

// Si bien no pertenecen al estándar ISO sino al BSD:

// int strcasecmp(const char * s1, const char *s2); que funciona como strcmp() pero es case insensitive.

// int strncasecmp(const char *s1, const char *s2, size_t n);